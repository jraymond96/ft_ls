## ft_ls

## DESCIPTION

The goal of this project was to recode fonction ls.

## PRINCIPAL NEW THINGS FOR ME

On this project i tried to optimise speed and do the most generic structure for adding lot of option easily.
The principal difference of lot's of option are impact of order's display so i choose to used binary tree because when new element comming he was directly sorted like i want.

* creation of Binary tree fonction with pointer of function for the if who determinated if the new element are the left or right son.
* Use bit fields for saving flags than user ask me. Using this systeme is for me the worst because i can stock 8 boolean in int...

** My final graduate on this project is 107/100 **

Cause of extra points : Powerfull of binary tree fonction and speed of my project (most speedy than real ls because i have less option)

## OPTION handled

| FLAGS | ACTION |
| --- | --- |
| -R | Recursively list subdirectories encountered | 
| -a | Include directory entries whose names begin with a dot (.) |
| -l | List in long format |
| -r | Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with sort by size) |
| -S | Sort files by size |
| -t |  Sort by time modified (most recently modified first) before sorting the operands by lexicographical order |
| -u | Use time of last access, instead of last modification of the file for sorting (-t) or long printing (-l) |
| -U | Use time of file creation, instead of last modification for sorting (-t) or long output (-l) |
