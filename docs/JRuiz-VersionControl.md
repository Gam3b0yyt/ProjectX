# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ Project and Portfolio I ]

- **[ Jose Ruiz]**
- **[ Sep 6, 2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ clear ]: Clear the Screen
- [ pwd ]: Print the "Working Directory"
- [ ls]: List files and folders
- [ ls -a]: List files and folders, including invisible files
- [ ls-lh]: List all files and folders, in human readable form
- [ cd [folder-name]]: Change directory
- [ cd /]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd . . ]: Change directory, go up one folder level
- [ cd . . / . . ]: Change directory, go up two folder levels
- [ cd ~/Desktop]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ When you type cd and then drag a folder from Finder or File Explorer into the Terminal window, Terminal automatically inserts the full absolute path to that folder (with spaces or special characters escaped). Pressing Return then changes the working directory to that folder without you having to type or remember the path manually. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ **Local Version Control** – Changes are tracked in a database or set of files stored only on the developer's local machine. This is simple but risky, since there's no backup if the machine is lost or damaged, and it's difficult to collaborate with others. **Centralized Version Control (CVCS)** – A single central server stores all versioned files, and developers "check out" files from that central location (e.g., Subversion, Perforce). This makes collaboration easier than local VCS, but if the central server goes down, no one can save versioned changes or collaborate at all. **Distributed Version Control (DVCS)** – Every developer has a full copy (clone) of the entire repository and its history on their own machine, not just the latest snapshot of files (e.g., Git, Mercurial). This provides redundancy, allows offline work, and makes collaboration and branching much more flexible.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone [repository-url] ]: Clone a repository
- [ git config --global user.name "Your name"]: Set-up a global user name
- [ git config --global user.email "you@example.com"]: Set-up a global email address (to match my GitHub account email)
- [ git status]: Shows the current state of your directory and staging area
- [ git add [file name]]: Add modified files to the next commit
- [ git commit -m "message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ To connect to GitHub over HTTPS from Terminal:  Copy the repository's HTTPS URL from the "Code" button on the GitHub repository page (it looks like `https://github.com/username/repository.git`). In Terminal, navigate to the folder where I want the project to live using `cd`.  Run `git clone https://github.com/username/repository.git` to download a full copy of the repository, including its history. When pushing changes with `git push`, GitHub prompts for authentication. Since GitHub retired password authentication, I sign in with a Personal Access Token (PAT) in place of a password, or authenticate once through the Git Credential Manager so future pushes/pulls don't require re-entering it.  Once authenticated, I can use standard commands like `git pull`, `git add`, `git commit`, and `git push` to sync changes between my local machine and GitHub. ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [A .gitignore file tells Git which files and folders to intentionally ignore/exclude from version control. This keeps unnecessary, sensitive, or machine-generated files out of the repository's history, keeping the repo cleaner and smaller.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [.DS_Store is a hidden file automatically created by macOS Finder to store folder-display settings (icon positions, view preferences, etc.). It's specific to a single machine and has no value to other collaborators or the project itself, so it's ignored to avoid cluttering the repository with irrelevant system files.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [Folders like node_modules/ (installed dependencies) or build output folders (e.g., build/, dist/, .vscode/, or compiled .o/.exe files for a C++ project) are good candidates. These can be regenerated automatically from source code or configuration, are often large, and differ between machines, so tracking them in Git just adds bloat and potential merge conflicts without adding real value.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Three Types of Version Control**  
[Site Address](https://www.someaddress.com/full/url/)

**Git Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Connecting to GitHub using Terminal**  
[Site Address](https://www.someaddress.com/full/url/)

**Using .gitignore and Why it's Important**  
[Site Address](https://www.someaddress.com/full/url/)
