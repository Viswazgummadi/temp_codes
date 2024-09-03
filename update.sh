#!/bin/bash

# Set the commit message, either passed as an argument or use a default message
commit_message="${1:-"Auto-commit: $(date +'%Y-%m-%d %H:%M:%S')"}"

# Navigate to your git repository
cd ~/workspace/cpp || { echo "Repository not found"; exit 1; }

# Add all changes to the staging area
git add .

# Commit the changes
git commit -m "$commit_message"

# Push the changes to the remote repository
git push origin maaster  # or the branch name you're working on

echo "Changes have been pushed to the repository."
