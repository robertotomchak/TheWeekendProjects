# Creates committee, based on constants below
POSSIBLE_CHOICES = "possible_choices.txt"  # path to file of possible choices for committee 
OLD_CHOICES = "old_choices.txt"  # path to file of old choices 
PRESENT_COMMITTEE = "committee.txt"  # path to present comitte

SIZE = 4  # size of the committee
KEEP = 1  # numbers of members to keep from old committee

from random import choice
import os

# gets members on given file
# if file doesnt exist, returns an empty list
# assumes there is one member per line
def get_members(filepath):
    if not os.path.exists(filepath):
        return []
    with open(filepath, "r") as file:
        choices = file.read().splitlines();
    return choices


# chooses k random members from given list
# if remove=True, also removes them from the list
def choose_members(members, k, remove=False):
    copy_members = members.copy()
    choosen = []
    for _ in range(k):
        member = choice(members)
        choosen.append(member)
        members.remove(member)
    if not remove:
        members = copy_members
    return choosen


# puts members in given file
# if file already exists, overwrites it
def define_members(filepath, members):
    with open(filepath, "w") as file:
        for member in members:
            file.write(member+"\n")


def main():
    possible_choices = get_members(POSSIBLE_CHOICES)
    old_choices = get_members(OLD_CHOICES)
    present_committee = get_members(PRESENT_COMMITTEE)

    # if there is no committe, create one from scratch
    if not present_committee:
        choosen_members = choose_members(possible_choices, SIZE, remove=True)
    # there is a committee and enough possible choices
    elif len(possible_choices) >= SIZE-KEEP:
        choosen_members = choose_members(possible_choices, SIZE-KEEP, remove=True)
    # if there is not enough possible choices, old choices became possible again
    # current possible members will be choosen
    else:
        choosen_members = possible_choices.copy()
        other_members = choose_members(old_choices, SIZE-KEEP-len(possible_choices), remove=True)

        choosen_members = choosen_members + other_members
        possible_choices = old_choices.copy()
        old_choices = []
    
    # members that will get out of committe
    if present_committee:
        # has to remove top KEEP members
        old_members = present_committee[:KEEP]
        present_committee = present_committee[KEEP:]
        not_kept_members = choose_members(present_committee, SIZE-2*KEEP, remove=True)
        not_kept_members = old_members + not_kept_members  # this order garantees that old members are at the top
        old_choices = old_choices + not_kept_members

    # new committee
    new_committee = present_committee + choosen_members

    if present_committee:
        print("Out of Committee: ", end="")
        print(*not_kept_members, sep=", ")
    print("New Committee: ", end="")
    print(*new_committee, sep=", ")

    status = input("save data? [y/n] ").lower()
    while status not in ["y", "n"]:
        print("ERROR: NOT VALID INPUT")
        status = input("save data? [y/n] ").lower()
    if status == "y":
        define_members(OLD_CHOICES, old_choices)
        define_members(PRESENT_COMMITTEE, new_committee)
        define_members(POSSIBLE_CHOICES, possible_choices)
        return


main()
