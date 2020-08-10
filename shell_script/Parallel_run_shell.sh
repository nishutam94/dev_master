#! /bin/bash
date="$(date +"%d-%m-%Y")"
logs=/root/nishant/snap/logs/$date/$1
mkdir -p $logs

for thread in 1 2 4 8 10 12 14 16 20 22 24 28;
do

for env in EIGEN  EIGENMKLDNN MKL ;do
source /root/nishant/snap/env/$env/bin/activate
declare -a bench_pids
l=0
h=0

for i in $(seq 1 $thread)
do	
numactl --physcpubind=${l}-${h} -m 0 python matmul.py --inter 1 --intra 1 2>&1 | tee $logs/${env}_MATMUL_2000_3100_256_1000_Thread_${thread}_core_${l}_${i}.txt &
bpid=$!
bench_pids+=($bpid)

l=$(( $l + 1))
h=$(( $h + 1))
done

for i in ${bench_pids[@]}
do
	wait $i                        
done

done
deactivate
sleep 5
done

echo "find the logs at : " $logs 