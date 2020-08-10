#!/bin/bash
#source /root/nishant/snap/env/TF_Non_MKL/bin/activate
source /root/nishant/snap/env/TF_MKL/bin/activate
echo "Training tuning started"

train_data=/root/nishant/snap/small
eval_data=/root/nishant/snap/small

date="$(date +"%d-%m-%Y")"
logs="/root/nishant/snap/training/logs/$date"
mkdir -p $logs

export KMP_SETTINGS=1
export KMP_BLOCKTIME=1
export MKL_VERBOSE=0
export MKLDNN_VERBOSE=0

ITR=1
for iteration in $(seq 1 $ITR);
do
for omp in  1 2 4 8;
export OMP_NUM_THREADS=$omp
do 
#for inter in $(seq 1 $STREAMEND);
for inter in  1 2 4 8 ;
do   
#for thread in $(seq 1 $THREADEND);
for intra in 1 2 4 8;
do
for batch in 1000;
do
for step in 0  ;
do   
   export log="$logs/snap_wnd_training_${batch}_${step}_${intra}_${inter}_${omp}.txt"
   echo "===========================================  Start Training $log ===================================" 
   cmd="python train_new.py --data_location $train_data --batch_size $batch --steps $step --inter_threads $inter --intra_threads $intra 2>&1 | tee  $log"
   echo $cmd
   bash -c "$cmd"

done
done 
done
done 
done
done

#python parser.py -p $logs/ -o $logs/summary.xlsx