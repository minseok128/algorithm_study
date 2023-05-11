#!/bin/bash

# Git add
git add .
git status
# Prompt for commit message without newline
printf "Enter the commit message: "
read -r commit_message

# Git commit
git commit -m "$commit_message"

# Git push
git push
