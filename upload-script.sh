#!/bin/bash

folder_path="/d/Workspace/leetcode-solution"
cd "$folder_path" || exit

# Look for changes in directory
changes=$(git status --porcelain)
if [ -n "$changes" ]; then
    git status
else
    read -p "No new solution(s) added. " var
    exit 0
fi

default_msg="add-solution"   # Default commit message
echo
read -p "Add files? (N/n to Cancel): " action
if [[ "$action" == [Nn] ]]; then
    echo "Aborted."
    exit 0
fi
git add .
read -p "Commit message (Enter to keep default): " new_msg
if [[ -z $new_msg ]]; then
    echo "Using default commit message: $default_msg"
    git commit -m $default_msg
    git push -u origin master

else
    echo "Using commit message: $new_msg"
    git commit -m $new_msg
    git push -u origin master
fi
echo
read -p "Changes Pushed to remote successfully. Press Enter to exit. " var
exit 0