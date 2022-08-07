import sys
import csv
import uuid
import os

fields = ["id","name", "phone", "date"] 

def main():
    print("\t\t\t\tMain Menu\n")
    print("\t\t<1>\tAdd a Member\n\n")
    print("\t\t<2>\tRemove a Member\n\n")
    print("\t\t<3>\tView all Members\n\n")
    print("\t\t<4>\tSearch Member by ID\n\n")
    print("\t\t<5>\tUpdate a Member\n\n")
    print("\t\t<6>\tClose Application\n\n")

    choice = int(input("Choice: "))

    if choice == 1:
        add_member()
    elif choice == 2:
        delete_member()
    elif choice == 3:
        view_members()
    elif choice == 4:
        search_member()
    # elif choice == 5:
    #     update_member()
    else:
        sys.exit(1)


def add_member():
    id  = uuid.uuid1()
    name = input("Name: ")
    phone_number = input("Phone number: ")
    data_issued = input("Date issued: ")
    member = {
    "id" :id,
    "name" :name,
    "phone" : phone_number,
    "date" : data_issued
    }

    file_name = "./Members.csv"

    if(os.path.exists(file_name) and os.path.isfile(file_name)):
        with open("Members.csv","a") as file:
            writer = csv.DictWriter(file, fieldnames=fields)
            writer.writerow(member)
        print("True")
    else:
        with open("Members.csv","w") as file:
            writer = csv.DictWriter(file, fieldnames=fields)
            writer.writeheader()
            writer.writerow(member)

    print(f"{name} was sucessfully added.", end="\n")


def delete_member():
    member_name = input("Please enter a member's name to be deleted: ")

    with open("Members.csv") as file, open("tmp.csv", "w") as tmp:
        try:
            reader = csv.reader(file)
            # writer  = csv.DictWriter(tmp,fieldnames=fields)
            # writer.writeheader()
            for row in reader:
                print(row)
                # if member_name not in row:
                #     writer.writerow(row)
        except ValueError:
            print("Member not found")

    # file_name = "./Members.csv"
    # if(os.path.exists(file_name) and os.path.isfile(file_name)):
    #     os.remove(file_name)
    #     print(f"{member_name} has been deleted.")
    
    # os.rename("tmp.csv","Members.csv")

def view_members():
    with open("Members.csv","r") as file: 
        reader = csv.DictReader(file)
        for row in reader:
            id = row["id"]
            name = row["name"]
            phone = row["phone"]
            date = row["date"]
            print("----------------------------------------------------------------------")
            print(f"ID: {id}")
            print(f"Name: {name}")
            print(f"Phone Number: {phone}")
            print(f"Data issued: {date}\n")


def search_member():
    member_name = input("Please enter a member's name: ")
    with open("Members.csv","r") as file: 
        reader = csv.DictReader(file)
        for row in reader:
            if member_name == row["name"]:
                id = row["id"]
                name = row["name"]
                phone = row["phone"]
                date = row["date"]
                print("----------------------------------------------------------------------")
                print(f"ID: {id}")
                print(f"Name: {name}")
                print(f"Phone Number: {phone}")
                print(f"Data issued: {date}\n")
                print("Member Found")
                

if __name__ == "__main__":
    main()