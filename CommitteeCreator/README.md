## Committee Creator
### Objective
Helps create a committee (a group of people that periodically changes), based on given rules.

### How to use
There are 5 constants that can be changed in the create_committee.py file:
- POSSIBLE_CHOICES: file that contains the name of everyone that can be selected to the new committee;
- OLD_CHOICES: file that contains everyone that already has been selected to old committees, and can't be selected to this new one (unless there's not enough possible choices);
- PRESENT_COMMITTEE: file that contains the names of the people of present committee;
- SIZE: size of committee;
- KEEP: how many people stay from last committee;

To use, just create a POSSIBLE_CHOICES file and write the name of all people that can be choosen (one in each line). Then, execute
```
python3 create_committee.py
```
It will also ask if you want to save the new committee choice. If yes, it will update the necessary files. Otherwise, nothing is saved, and you can execute again to get a different committee.

### Limitations
- The committe is choosen randomly. If you want to include certain attributtes (example: have a certain number of women in the committee) you can build these features on top of this software;
- If there's not enough possible choices to build a committee, it will take people from OLD_CHOICES. This means that someone that was on the second to last committee can be choosen (but never from last committee);
- There needs to be at least 2*SIZE - KEEP members in total. Otherwise, it can't build a committee, since it would need to keep more members than requested.
- If you already have a committe, you need to do some manual work. Put the present committee in PRESENT_COMMITTEE, the old members in OLD_CHOICES and all possible members in POSSIBLE_MEMBERS.
