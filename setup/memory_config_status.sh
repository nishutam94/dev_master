#!/bin/bash

# memory_audit.sh — System Memory & Architecture Report
# Run this as root or with sudo to collect all information properly

OUTPUT="memory_audit_report_$(hostname)_$(date +%F_%T).txt"

echo "🔍 Collecting system memory and architecture information..."
echo "Generating report: $OUTPUT"
echo "==== System Memory & Architecture Audit Report ====" > "$OUTPUT"
echo "Generated on: $(date)" >> "$OUTPUT"
echo "Hostname: $(hostname)" >> "$OUTPUT"
echo "OS: $(uname -sr)" >> "$OUTPUT"
echo >> "$OUTPUT"

# 1. Total Physical Memory
echo "1. 🔹 Total Physical Memory:" >> "$OUTPUT"
grep MemTotal /proc/meminfo >> "$OUTPUT"
echo >> "$OUTPUT"

# 2. Application Memory Config (example for Java apps)
echo "2. 🔹 Application Memory Config (Java example):" >> "$OUTPUT"
ps -ef | grep java | grep -v grep | while read -r line; do
    echo "$line" >> "$OUTPUT"
    echo "$line" | grep -oP '(-Xms|-Xmx)[^\s]*' >> "$OUTPUT"
done
echo >> "$OUTPUT"

# 3. Memory Allocators in Use
echo "3. 🔹 Memory Allocators in Use (by PID):" >> "$OUTPUT"
for pid in $(pgrep -d' ' -x); do
    exe=$(readlink /proc/$pid/exe 2>/dev/null)
    if [[ -n "$exe" ]]; then
        echo "PID $pid: $exe" >> "$OUTPUT"
        ldd "$exe" 2>/dev/null | grep -i malloc >> "$OUTPUT"
    fi
done
echo >> "$OUTPUT"

# 4. Memory Type and Speed
echo "4. 🔹 Memory Type and Speed:" >> "$OUTPUT"
sudo dmidecode --type 17 | grep -E 'Size|Type:|Speed:' >> "$OUTPUT"
echo >> "$OUTPUT"

# 5. Memory Testing Tool Present?
echo "5. 🔹 Memory Testing Tool:" >> "$OUTPUT"
which memtester &>> "$OUTPUT" && echo "memtester is available." >> "$OUTPUT" || echo "memtester is NOT installed." >> "$OUTPUT"
echo >> "$OUTPUT"

# 6. System Architecture - NUMA or UMA
echo "6. 🔹 System Architecture (NUMA/UMA):" >> "$OUTPUT"
lscpu | grep "NUMA" >> "$OUTPUT"
numactl --hardware >> "$OUTPUT" 2>/dev/null
echo >> "$OUTPUT"

# 7. NUMA-Aware OS and Tunables
echo "7. 🔹 NUMA-Awareness and Tunables:" >> "$OUTPUT"
numactl --show >> "$OUTPUT"
echo "zone_reclaim_mode: $(cat /proc/sys/vm/zone_reclaim_mode)" >> "$OUTPUT"
echo >> "$OUTPUT"

# 8. Memory Socket Attachment
echo "8. 🔹 Memory Socket Topology:" >> "$OUTPUT"
command -v lstopo &> /dev/null && lstopo --no-io --of console >> "$OUTPUT" || echo "lstopo not installed." >> "$OUTPUT"
echo >> "$OUTPUT"

# 9. Memory Buses Info
echo "9. 🔹 Memory Buses (inferred from DMIDECODE):" >> "$OUTPUT"
sudo dmidecode --type memory | grep -i 'locator\|bank\|speed' >> "$OUTPUT"
echo >> "$OUTPUT"

# 10. CPU Cache Info
echo "10. 🔹 CPU Cache Sizes:" >> "$OUTPUT"
lscpu | grep -i "cache" >> "$OUTPUT"
echo >> "$OUTPUT"

# 11. BIOS Settings
echo "11. 🔹 BIOS Settings:" >> "$OUTPUT"
sudo dmidecode --type bios >> "$OUTPUT"
echo >> "$OUTPUT"

# 12. Large Pages
echo "12. 🔹 Huge Pages Configuration:" >> "$OUTPUT"
grep Huge /proc/meminfo >> "$OUTPUT"
cat /sys/kernel/mm/transparent_hugepage/enabled >> "$OUTPUT"
echo >> "$OUTPUT"

# 13. Memory Overcommit
echo "13. 🔹 Memory Overcommit Settings:" >> "$OUTPUT"
echo "overcommit_memory = $(cat /proc/sys/vm/overcommit_memory)" >> "$OUTPUT"
echo "overcommit_ratio = $(cat /proc/sys/vm/overcommit_ratio)" >> "$OUTPUT"
echo >> "$OUTPUT"

# Done
echo "✅ Report complete. Saved to: $OUTPUT"
