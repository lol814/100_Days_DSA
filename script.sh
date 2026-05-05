#!/bin/bash

start_date="2026-02-01"

# pick 7 unique random skip days (1–82)
skip_days=($(shuf -i 1-82 -n 7))

echo "Skipping days: ${skip_days[@]}"

for i in $(seq -f "%03g" 1 82)
do
    file="Day_${i}.c"

    if [ ! -f "$file" ]; then
        echo "❌ Missing $file"
        continue
    fi

    day_num=$((10#$i))

    # check skip
    skip_flag=0
    for s in "${skip_days[@]}"
    do
        if [ "$day_num" -eq "$s" ]; then
            skip_flag=1
            break
        fi
    done

    if [ $skip_flag -eq 1 ]; then
        echo "⏭ Skipping Day $i"
        continue
    fi

    # realistic time (10 AM – 7 PM)
    hour=$((RANDOM % 10 + 10))
    minute=$((RANDOM % 60))
    second=$((RANDOM % 60))

    day_index=$((day_num - 1))

    commit_date=$(date -d "$start_date +$day_index day" +"%Y-%m-%d")
    full_date="$commit_date $(printf "%02d:%02d:%02d" $hour $minute $second)"

    git add "$file"

    GIT_AUTHOR_DATE="$full_date" \
    GIT_COMMITTER_DATE="$full_date" \
    git commit -m "DONE Day $i"

    echo "✅ Committed $file → $full_date"
done
