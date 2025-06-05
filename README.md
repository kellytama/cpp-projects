# CPP Projects

This is a collection of personal programs that I tried making to sharpen my programming skills and solve problems through code. They are simple and educational, with sparse comments. 

# Setting up git
Prerequisite: A remote repo set up on GitHub.

To initialize Git (version control), cd into local repo (your local machine) and do the following: 
1. `git init` to create an empty git repo or reinitialize an existing one 
2. `git remote add origin https://github.com/<username>/<remote-repo>.git`
3. `git remote -v` to check the urls of the remote repos that are configured to your local repo
4. `git add <filename> -u` -u is for adding only modified files, vs `add .` which adds ALL files in the local directory
5. `git status -uno` u (untracked) (no), meaning do not show untracked files
6. `git commit -m "A descriptive commit message"`
7. `git push origin main` to push local commits to the remote repo with alias origin and update the branch named main   

To access `git` manual for `init` for example, do `git --help init`.