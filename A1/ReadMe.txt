COMP2404 
Assignment 1
Prof. Louis Nel

Tarek Sanger 
Student Number: *********

October 2nd, 2019


Uncompress the file using: 
unzip mytunes.zip


To compile the code run: 
make

To run the executible and begin testing:
cd bin
./mytunes


To clean up the code run: 
make clean


For Testing .read:
.read 2404A1demoOfCommandsScript.txt
.read 2404A1insertDataScript.txt

Notes:
    - If the add, delete, show and log are entered with incorrect flags or just the flag without variables after that flag it will only print the command that it is executing. This is because I have a for-loop printing the variables that came after the flag... When a command is entered it creates an operation and that operation creates a map<string, vector<string>> (a 'toDo list') from everything entered after the command (i.e add). Where the flag is the key and the value is a vector of variables given after the flag to preform the operation.

    (i.e 
    add -s 1110 "Dear Prudence" "John Lennon" "Paul McCartney" -t 111 1174 5
    becomes,
    {
        {-s, {1110, Dear Prudence, John Lennon, Paul McCartney}
        {-t {111, 1174, 5}}
    }
    )