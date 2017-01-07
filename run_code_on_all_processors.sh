#! /bin/bash
SRC=${1:-1.c}
MULTIPLIER=${2:-1}
CORES=$(grep -c ^processor /proc/cpuinfo);
THREADS=$((${CORES} * ${MULTIPLIER}))

echo Testing ${SRC} with ${THREADS} threads.

killall -q b;

gcc -O3 -o /tmp/b ${1:-1.c} &&
time (
  for ((i=0; i < ${THREADS}; ++i)); do
    echo Thread ${i} $(/tmp/b) &
  done;
  wait
)

echo $(grep -oE 'MHz.*' /proc/cpuinfo| sort -n)
