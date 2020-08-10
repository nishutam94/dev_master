#!bin/bash
echo "Inference started"
eval_data=/root/nishant/snap/large
IPath1=/root/nishant/snap/models/models/recommendation/tensorflow/wide_deep_large_ds/inference
IPath2=/root/nishant/snap/models/benchmarks
graph=/root/nishant/snap/graph
date="$(date +"%d-%m-%Y")"
logs="/root/nishant/snap/inference/logs/$date/kmp0_all3"
mkdir -p $logs


for env in TF_MKL TF_Non_MKL TF_EIGEN ; do
#for env in TF_MKL_EIGEN; do
source /root/nishant/snap/env/$env/bin/activate
export LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libtcmalloc.so.4
for KMP_SETTINGS in 1;do
 for KMP_BLOCKTIME in 1;do
  for KMP_AFFINITY in 'noverbose,warnings,respect,granularity=core,none';do
  #for KMP_AFFINITY in 'compact,1,0,granularity=fine';do
   for OMP_NUM_THREAD in 1;do
    for inter in 8;do
     for intra in 8; do
      for iteration in 1; do
      for batch in 1000;do
        for numactl in '--physcpubind=0-0,48-48' '--physcpubind=0-0'; do

        export KMP_SETTINGS=$KMP_SETTINGS
        export KMP_BLOCKTIME=$KMP_BLOCKTIME
        export KMP_AFFINITY=$KMP_AFFINITY
        export OMP_NUM_THREAD=$OMP_NUM_THREAD
        export log="$logs/${env}_optimized_${numactl}_${batch}_${OMP_NUM_THREAD}_${intra}_${inter}_${KMP_SETTINGS}_${KMP_BLOCKTIME}_${KMP_AFFINITY}_${iteration}.txt"
        echo "===========================================  Start Training $log ===================================" 

         cmd="numactl $numactl -m 0  python $IPath2/launch_benchmark.py \
            --model-name wide_deep_large_ds \
            --precision fp32 \
            --mode inference \
            --framework tensorflow \
            --benchmark-only \
            --socket-id 0 \
            --batch-size $batch \
            --in-graph $graph/fp32_graph_optimized.pb \
            --data-location $eval_data/eval_preprocessed_eval_new_features.tfrecords \
            --num-intra-threads $intra \
            --num-inter-threads $inter \
            --num_omp_threads=$OMP_NUM_THREAD \
            -- kmp_block_time=$KMP_BLOCKTIME kmp_settings=$KMP_SETTINGS  kmp_affinity=$KMP_AFFINITY \
            2>&1 | tee  $log" 
   

          echo $cmd
          bash -c "$cmd"
          sleep 10


       
        export log="$logs/${env}_unoptimized_${numactl}_${batch}_${OMP_NUM_THREAD}_${intra}_${inter}_${KMP_SETTINGS}_${KMP_BLOCKTIME}_${KMP_AFFINITY}_${iteration}.txt"
        echo "===========================================  Start Training $log ===================================" 

        cmd="numactl $numactl -m 0 \
          python $IPath1/run_inference_criteo_unoptimized_new.py \
          --graph  $graph/fp32_graph.pb \
          --data_dir $eval_data/eval_431.csv \
          --batch_size $batch \
          --intra $intra\
          --inter $inter \
          --omp $OMP_NUM_THREAD \
           2>&1 | tee  $log"
      echo $cmd
      bash -c "$cmd" 
      sleep 10
      done
     done 
    done 
   done 
  done 
 done
done
done
done
deactivate
sleep10
done