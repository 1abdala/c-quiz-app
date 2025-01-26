#include <iostream>
#include <iomanip>
#include<fstream>
#include <string>
#include <ctime>   
#include <cstdlib> 
using namespace std;

struct TFQA {
    string question;
    bool answer;
};

struct player {

    string name;
    int TF_TopicsScore[11];
    int Mcq_TopicsScore[11];

};

struct feed_back {
    player note;

};

player currentplayer;
feed_back fb;


int currentTopic;
int score = 0;
int* ptr = &score;

//SCORES FUNCTIONS.
void displaygraph(int topicsScore[11]) {

    int star;
    for (int i = 0; i < 11; i++) {

        cout << "Chapter " << i + 1;
        star = topicsScore[i];
        for (int j = 0; j < star; j++) {
            cout << " * ";
        }

        cout << endl;
    }
    


}
void top3scores(int topicsScore[11], int top3scores[3]) {
    int hisc[3] = { 0 };

    for (int i = 0; i < 11; i++) {

        if (topicsScore[i] > hisc[0]) {
            hisc[0] = topicsScore[i];
            if (hisc[0] > hisc[1]) {
                swap(hisc[0], hisc[1]);
            }
            if (hisc[1] > hisc[2]) {
                swap(hisc[1], hisc[2]);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        top3scores[i] = hisc[i];

    }


}
void displaytop3scores(int top3[3]) {

    cout << "Top 3 Scores: ";
    for (int i = 0; i < 3; i++) {
        cout << top3[i] << " ";
    }


}

//MCQ FUNCTIONS.
void MultiQuestionsScreen() {
    system("cls");
    srand(time(0));
    int quesnum, topic;
    char choice;
    score = 0;

    cout << "here is multichoise screen \n\n";
    do {

        string topics[11] = { "Introduction to Computer & Programming","Problem Solving","Basic Elements of C++","Selection Control Structure",
            "Repetition Control Structure","Function","Array","String & File","Structured Data","Pointer","Mix questions" };

        int size = sizeof(topics) / sizeof(topics[0]);
        for (int i = 0; i < size; i++) {
            cout << i + 1 << " ." << topics[i] << endl;

        }

        do {
            cout << "Enter the topic you want to test yourself in (1-11), or press any other number to get mixed chapters questions: ";

            if (!(cin >> topic)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number.\n";
                continue;
            }

            if (topic >= 1 && topic <= 11) {
                break;
            }
            else {
                cout << "Enter a valid number between 1 and 11.\n";
            }
        } while (true);


        if (topic == 1) {



            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);

            cout << endl;
            string lec1[15][6] = {
            {
                " What are the main components of a computer system?",
                "A) Input devices", "B) Output devices", "C) CPU, memory, and storage", "D) None of the above",
                "C"
            },
            {
                "Which of these is an example of computer hardware?",
                "A) Operating system", "B) Printer", "C) Python", "D) C++",
                "B"
            },
            {
                "What type of language does a computer understand natively?",
                "A) Assembly language", "B) High-level language", "C) Machine language", "D) None of the above",
                "C"
            },
            {
                " Which programming language is closest to the machine language?",
                "A) Assembly language", "B) High-level language", "C) Python", "D) Java",
                "A"
            },
            {
                " Which of the following is a high-level programming language?",
                "A) Machine language", "B) Assembly language", "C) C++", "D) None of the above",
                "C"
            },
            {
                " How does a computer execute a program?",
                "A) It directly runs the high-level code", "B) It converts the program into machine language", "C) It stores the code as an image", "D) None of the above",
                "B"
            },
            {
                "Which step is involved in compiling a program?",
                "A) Writing the code", "B) Linking the code", "C) Translating source code to machine code", "D) Running the program",
                "C"
            },
            {
                " What is the purpose of linking a program?",
                "A) To write the program", "B) To compile the code", "C) To connect separate code files into one executable", "D) To input data",
                "C"
            },
            {
                " Which IDE is commonly used for C++ console applications?",
                "A) Eclipse", "B) MS Visual C++", "C) Xcode", "D) Sublime Text",
                "B"
            },
            {
                " Which action comes first in the programming process?",
                "A) Linking the program", "B) Writing the code", "C) Running the program", "D) Compiling the program",
                "B"
            },
            {
                " Which of the following is the correct syntax to output in C++?",
                "A) print(\"Hello World\")", "B) echo \"Hello World\";", "C) cout << \"Hello World\";", "D) System.out.print(\"Hello World\");",
                "C"
            },
            {
                " What does the C++ #include directive do?",
                "A) Executes a library function", "B) Imports external header files", "C) Declares the main function", "D) None of the above",
                "B"
            },
            {
               "What is the correct file extension for C++ source code files?", "A) .cpp", "B) .c", "C) .cs", "D) .py",
                          "A"
             },
            {
               " Which of the following is used to declare a constant variable in C++?", "A) final", "B) constant", "C) const", "D) #define",
                 "C"

             },
            {
                " What does the keyword 'int' specify in C++?","A) A function", "B) A character", "C) An integer data type", "D) A header file",
                 "C"
             }
            };
            int curscore = 0;
            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec1[random][0] << endl;
                cout << lec1[random][1] << endl;
                cout << lec1[random][2] << endl;
                cout << lec1[random][3] << endl;
                cout << lec1[random][4] << endl;


                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec1[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec1[random][5] << endl;

                }
                cout << "\n-------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[0] = curscore;
            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;



        }
        else if (topic == 2) {
            cout << "\nEnter how many  questions do you want (1-15) :";
            cin >> quesnum;

            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;

            string lec2[15][6] = {
                   {
                       " What is the first step in problem-solving?",
                       "A) Implement a solution", "B) Define the problem", "C) Write pseudocode", "D) Test the solution",
                       "B"
                   },
                   {
                       " What technique is often used to represent the flow of a program visually?",
                       "A) Pseudocode", "B) Flowchart", "C) Algorithms", "D) Function diagrams",
                       "B"
                   },
                   {
                       " Which of the following is NOT a feature of pseudocode?",
                       "A) Uses natural language constructs", "B) Is platform-independent", "C) Runs directly on a computer", "D) Represents program logic",
                       "C"
                   },
                   {
                       "What does a flowchart represent?",
                       "A) The actual program code", "B) The logical steps of solving a problem", "C) The pseudocode", "D) None of the above",
                       "B"
                   },
                   {
                       " In a flowchart, which symbol represents the start and end points?",
                       "A) Rectangle", "B) Parallelogram", "C) Oval", "D) Diamond",
                       "C"
                   },
                   {
                       " In pseudocode, which construct is typically used to represent decision making?",
                       "A) Loop", "B) Conditional (if, else)", "C) Function", "D) None of the above",
                       "B"
                   },
                   {
                       " Which of the following is true about a function in programming?",
                       "A) A function is used to define the main program", "B) A function is used to perform specific tasks or computations", "C) Functions cannot return values", "D) Functions are optional in C++",
                       "B"
                   },
                   {
                       " What is the primary purpose of writing an algorithm?",
                       "A) To execute a program", "B) To test the code", "C) To plan and define the steps for solving a problem", "D) To compile the program",
                       "C"
                   },
                   {
                       " Which step comes last in the problem-solving process?",
                       "A) Analyzing the problem", "B) Designing an algorithm", "C) Implementing a solution", "D) Testing the solution",
                       "D"
                   },
                   {
                       " Which of these is an example of an algorithm?",
                       "A) Sorting a list of numbers", "B) Displaying a message", "C) Checking if a number is even", "D) All of the above",
                       "D"
                   },
                   {
                       " What do we call a flowchart symbol with four sides that represents a process or task?",
                       "A) Oval", "B) Parallelogram", "C) Rectangle", "D) Diamond",
                       "C"
                   },
                   {
                       "In pseudocode, what does the word REPEAT typically signify?",
                       "A) Start of a function", "B) Start of a loop", "C) Conditional checking", "D) End of the program",
                       "B"
                   },
                   {
                       " Which of the following can a function return?",
                       "A) Nothing", "B) A value", "C) A code error", "D) A flowchart",
                       "B"
                   },
                   {
                       " Which algorithmic step defines the exact process or rules for solving a problem?",
                       "A) Input", "B) Output", "C) Process", "D) Testing",
                       "C"
                   },
                   {
                       " How do pseudocode and flowcharts help in program design?",
                       "A) They write the program code for you", "B) They allow you to define logic without writing actual code", "C) They test the program", "D) They debug the program",
                       "B"
                   }
            };
            int curscore = 0;
            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec2[random][0] << endl;
                cout << lec2[random][1] << endl;
                cout << lec2[random][2] << endl;
                cout << lec2[random][3] << endl;
                cout << lec2[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec2[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec2[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[1] = curscore;
            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }



        else if (topic == 3) {

            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;
            string lec3[15][6] = {
  {
      " Which of the following is NOT a keyword in C++?",
      "A) int", "B) return", "C) function", "D) for",
      "C"
  },
  {
      " Which of the following is an example of an identifier in C++?",
      "A) 123variable", "B) @variable", "C) variable_name", "D) if",
      "C"
  },
  {
      "What is the role of an operator in C++?",
      "A) To declare variables", "B) To perform operations on variables and values", "C) To define the data types", "D) To print output",
      "B"
  },
  {
      " Which of the following is a relational operator in C++?",
      "A) +", "B) =", "C) >", "D) &&",
      "C"
  },
  {
      "How do we read input in C++?",
      "A) cin", "B) cout", "C) printf", "D) scanf",
      "A"
  },
  {
      " Which of the following is the correct syntax to declare an integer variable in C++?",
      "A) int x;", "B) integer x;", "C) x int;", "D) var x;",
      "A"
  },
  {
      " What does the = operator do in C++?",
      "A) Compares two values", "B) Assigns a value to a variable", "C) Adds two values", "D) Divides two values",
      "B"
  },
  {
      " Which of these is an arithmetic operator in C++?",
      "A) *", "B) /", "C) %", "D) All of the above",
      "D"
  },
  {
      " Which type of operator is used to combine two conditions in C++?",
      "A) Relational operator", "B) Logical operator", "C) Assignment operator", "D) Increment operator",
      "B"
  },
  {
      " What is the data type used to represent a single character in C++?",
      "A) int", "B) float", "C) char", "D) double",
      "C"
  },
  {
      " In C++, what is the correct way to output Hello, World!?",
      "A) cout Hello, World!;", "B) cout << Hello, World!;", "C) print << Hello, World!;", "D) printf(\"Hello, World!\");",
      "B"
  },
  {
      " Which operator is used for logical AND in C++?",
      "A) &&", "B) &", "C) ||", "D) !",
      "A"
  },
  {
      " Which of these is a valid C++ statement for assigning the value 5 to a variable x?",
      "A) 5 = x;", "B) x == 5;", "C) x = 5;", "D) x => 5;",
      "C"
  },
  {
      " What is the output for the following C++ code? cout << 10 / 3;",
      "A) 3.3333", "B) 3", "C) 3.0", "D) error",
      "B"
  },
  {
      "What does the format specifier endl do in C++?",
      "A) Skips a line", "B) Ends the current line and outputs a newline", "C) Adds spaces between words", "D) Prints the word 'endl'",
      "B"
  }
            };
            int curscore = 0;
            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec3[random][0] << endl;
                cout << lec3[random][1] << endl;
                cout << lec3[random][2] << endl;
                cout << lec3[random][3] << endl;
                cout << lec3[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec3[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec3[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[2] = curscore;
            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }


        else if (topic == 4) {


            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);

            cout << endl;
            string lec4[15][6] = {
   {
       " Which of the following is a valid if statement in C++?",
       "A) if x == 5 { }", "B) if (x == 5) { }", "C) if x == 5: { }", "D) if x == 5;",
       "B"
   },
   {
       " What does the following if statement do? if (x > 10) { cout << \"Greater\"; }",
       "A) It checks if x is less than 10", "B) It checks if x is greater than 10", "C) It always outputs 'Greater'", "D) It checks if x is equal to 10",
       "B"
   },
   {
       " What is the output of the following code? int x = 7; if(x % 2 == 0) { cout << \"Even\"; } else { cout << \"Odd\"; }",
       "A) Even", "B) Odd", "C) 7", "D) Nothing",
       "B"
   },
   {
       " In C++, which operator is used for equality check in an if statement?",
       "A) =", "B) =", "C) !=", "D) ==",
       "D"
   },
   {
       " What does the else keyword do in C++?",
       "A) Provides a default case when the if condition is false", "B) Initializes a variable", "C) Ends a function", "D) Terminates the program",
       "A"
   },
   {
       " What is the correct syntax for a switch statement in C++?",
       "A) switch (x) { case 1: break; case 2: break; }", "B) switch x { case 1: break; }", "C) case 1: switch { break; }", "D) if(x) switch { break; }",
       "A"
   },
   {
       " What does a switch statement do?",
       "A) Makes a selection based on a boolean condition", "B) Executes the code matching the case value", "C) Loops until a certain condition is met", "D) Initializes a variable",
       "B"
   },
   {
       " What is the result of this code? int x = 8; switch(x) { case 1: cout << \"One\"; break; case 8: cout << \"Eight\"; break; }",
       "A) One", "B) Eight", "C) Error", "D) Nothing",
       "B"
   },
   {
       " What will be printed if x = 5; if (x > 4) cout << \"True\"; else cout << \"False\";?",
       "A) True", "B) False", "C) 4", "D) Error",
       "A"
   },
   {
       " How many times will this code run? int x = 0; while (x < 5) { if (x == 3) break; x++; }",
       "A) Infinite loop", "B) 3 times", "C) 4 times", "D) 5 times",
       "B"
   },
   {
       " What will be the output of this code? int x = 10; if (x < 5) { cout << \"Small\"; } else { cout << \"Big\"; }",
       "A) Small", "B) Big", "C) Error", "D) Nothing",
       "B"
   },
   {
       " Which of these statements is true about the if-else structure?",
       "A) The else statement is mandatory", "B) else block is executed if the if condition is false", "C) Only one else condition can exist", "D) if-else is an iteration structure",
       "B"
   },
   {
       " In C++, which structure allows for multiple conditions to be checked within one block?",
       "A) switch", "B) if-else ladder", "C) for loop", "D) do-while loop",
       "B"
   },
   {
       " Which of the following operators are used in selection control in C++?",
       "A) ++", "B) &&", "C) ==", "D) All of the above",
       "C"
   },
   {
       " What does a break statement do inside a switch or loop?",
       "A) Ends the program", "B) Breaks out of the nearest loop or switch", "C) Restarts the program", "D) Terminates the current function",
       "B"
   }
            };
            int curscore = 0;
            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec4[random][0] << endl;
                cout << lec4[random][1] << endl;
                cout << lec4[random][2] << endl;
                cout << lec4[random][3] << endl;
                cout << lec4[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec4[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec4[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[3] = curscore;


            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }



        else if (topic == 5) {

            int curscore = 0;
            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;
            string lec5[15][6] = {
   {
       " What type of loop executes a block of code a specified number of times?",
       "A) for", "B) while", "C) do-while", "D) if",
       "A"
   },
   {
       " Which of these loops will execute the block of code at least once?",
       "A) for", "B) while", "C) do-while", "D) None",
       "C"
   },
   {
       " What is the output of the following code? int x = 0; while (x < 3) { cout << x; x++; }",
       "A) 123", "B) 012", "C) 321", "D) 0",
       "B"
   },
   {
       " What will the following for loop print? for(int i = 1; i <= 5; i++) { cout << i << \" \"; }",
       "A) 1 2 3 4 5", "B) 0 1 2 3 4", "C) 5 4 3 2 1", "D) 5 4 3 2",
       "A"
   },
   {
       " Which loop is guaranteed to execute at least once in C++?",
       "A) for loop", "B) do-while loop", "C) while loop", "D) None",
       "B"
   },
   {
       " What is the result of the following code? int x = 5; do { x--; } while(x > 0); cout << x;",
       "A) 0", "B) 5", "C) -1", "D) 1",
       "A"
   },
   {
       " How does the break statement work in loops?",
       "A) Stops the program", "B) Breaks the loop and continues with the next statement", "C) Skips the loop", "D) Does nothing in loops",
       "B"
   },
   {
       " What happens when continue is encountered inside a loop?",
       "A) It stops the loop", "B) It skips the rest of the code in the current iteration", "C) It executes the loop again", "D) Nothing happens",
       "B"
   },
   {
       " What is the output of the following do-while loop? int x = 3; do { cout << x; x++; } while(x < 3);",
       "A) 3", "B) 3 4", "C) 4", "D) Error",
       "A"
   },
   {
       " What does the following loop do? int i = 0; while (i < 5) { cout << i; i++; }",
       "A) It runs indefinitely", "B) Prints 01234", "C) Prints 54321", "D) Prints 1 2 3 4",
       "B"
   },
   {
       " What is the condition that would stop a while loop from running?",
       "A) When the condition is true", "B) When the condition is false", "C) After the loop executes 5 times", "D) When the value of the loop variable is 0",
       "B"
   },
   {
       " In a for loop, which part determines how many times the loop will run?",
       "A) The initial value", "B) The condition", "C) The increment/decrement step", "D) All of the above",
       "D"
   },
   {
       " What will be printed from this code? int x = 0; for(int i = 1; i <= 5; i++) { x += i; } cout << x;",
       "A) 0", "B) 5", "C) 15", "D) 20",
       "C"
   },
   {
       " What is the result of the following for loop? int i = 0; for (int j = 0; j < 5; j++) { i += 2; } cout << i;",
       "A) 8", "B) 5", "C) 4", "D) 0",
       "A"
   },
   {
       " Which loop statement would be best to use when you need to loop at least once and only then check for the condition?",
       "A) while loop", "B) do-while loop", "C) for loop", "D) None of the above",
       "B"
   }
            };

            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec5[random][0] << endl;
                cout << lec5[random][1] << endl;
                cout << lec5[random][2] << endl;
                cout << lec5[random][3] << endl;
                cout << lec5[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec5[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec5[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[4] = curscore;

            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }

        else if (topic == 6) {

            int curscore = 0;
            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;
            string lec6[15][6] = {
{
    " What is the purpose of a function in C++?",
    "A) To execute code directly", "B) To divide a program into smaller parts", "C) To declare variables", "D) To input and output data",
    "B"
},
{
    " What is the correct way to declare a function in C++?",
    "A) function_name();", "B) return_type function_name() {}", "C) void function_name {};","D) function_name {return;} ",
    "B"
},
{
    " What is the return type of a function that does not return any value?",
    "A) int", "B) void", "C) char", "D) bool",
    "B"
},
{
    " Which of the following is a valid function call in C++?",
    "A) func();", "B) function_name()", "C) function();", "D) All of the above",
    "D"
},
{
    " In C++, a function can take arguments. What is passed to the function during its call?",
    "A) Variables", "B) Values of the variables", "C) Type of the argument", "D) Function signature",
    "B"
},
{
    " What happens if a function has no return type but tries to return a value?",
    "A) Compilation error", "B) Value is ignored", "C) The program will run normally", "D) Runtime error",
    "A"
},
{
    " Which function declaration would correctly define a function that takes two integers and returns their sum as an integer?",
    "A) int addNumbers(int a, int b) {}", "B) void addNumbers(int a, int b) {}", "C) float addNumbers(int a, int b) {}", "D) int addNumbers() {}",
    "A"
},
{
    " Which of these keywords is used to return a value from a function?",
    "A) return", "B) yield", "C) break", "D) continue",
    "A"
},
{
    " Which of the following is an example of a function prototype in C++?",
    "A) int add(int, int);", "B) add(int a, int b) {}", "C) int add(int a, int b) {}", "D) function void add(){}",
    "A"
},
{
    " What is the result of calling this function? void greet(){ cout << \"Hello, World!\"; }",
    "A) Prints 'Hello, World!'", "B) No output", "C) Returns a string", "D) Compilation error",
    "A"
},
{
    " In C++, what is the main function?",
    "A) A function used to run the entire program", "B) A function to display results", "C) A library function", "D) A function that is never called",
    "A"
},
{
    " What does the keyword inline before a function mean?",
    "A) The function is called recursively", "B) The function should run in the main program block", "C) The function is embedded at the place where it’s used", "D) The function should not be used",
    "C"
},
{
    " Which of the following is a correct way to call a function with arguments?",
    "A) addNumbers(2, 3);", "B) int addNumbers(2, 3);", "C) addNumbers; 2 3", "D) addNumbers(2+3);",
    "A"
},
{
    " What would happen if a function was called but the function body did not have any statements?",
    "A) Program crashes", "B) Nothing happens", "C) Compiler error", "D) Nothing happens, but no result is printed",
    "B"
},
{
    " In C++, can a function return multiple values?",
    "A) Yes, by using arrays or pointers", "B) No, a function can return only one value", "C) Yes, by using multiple return statements", "D) Yes, by using global variables",
    "A"
}
            };

            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec6[random][0] << endl;
                cout << lec6[random][1] << endl;
                cout << lec6[random][2] << endl;
                cout << lec6[random][3] << endl;
                cout << lec6[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec6[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec6[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[5] = curscore;

            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }


        else if (topic == 7) {


            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;
            string lec7[15][6] = {
{
    " How do you declare an array of 10 integers in C++?",
    "A) int arr[10];", "B) int arr(10);", "C) array int[10];", "D) int[10] arr;",
    "A"
},
{
    " What is the index of the first element in an array in C++?",
    "A) 0", "B) 1", "C) -1", "D) None of the above",
    "A"
},
{
    " How do you access the 5th element of an array in C++?",
    "A) arr[5];", "B) arr[4];", "C) arr[6];", "D) arr(5);",
    "B"
},
{
    " What is the maximum index of an array arr[10]; in C++?",
    "A) 9", "B) 10", "C) 11", "D) 10-1",
    "A"
},
{
    " Which of the following is correct to declare a two-dimensional array with 2 rows and 3 columns?",
    "A) int arr[2][3];", "B) int arr[2,3];", "C) int arr[3][2];", "D) int arr[3, 2];",
    "A"
},
{
    " Which operator is used to get the address of the first element of an array?",
    "A) *", "B) &", "C) []", "D) ->",
    "B"
},
{
    " What is the result of accessing an array element out of bounds?",
    "A) Compilation error", "B) Undefined behavior", "C) Runtime error", "D) The value becomes zero",
    "B"
},
{
    " Which statement correctly initializes an array with values 5, 10, 15?",
    "A) int arr[] = {5, 10, 15};", "B) int arr[3] = (5, 10, 15);", "C) int arr = 5, 10, 15;", "D) int arr[3] = {5 10 15};",
    "A"
},
{
    " What is the size of the array int arr[5]?",
    "A) 5", "B) sizeof(arr) / sizeof(arr[0])", "C) 4", "D) 6",
    "B"
},
{
    " In a C++ array, which index is the last element if the array has 20 elements?",
    "A) 19", "B) 20", "C) 0", "D) 1",
    "A"
},
{
    " What is the output of the following code? int arr[] = {1, 2, 3}; cout << arr[1];",
    "A) 1", "B) 2", "C) 3", "D) Compilation error",
    "B"
},
{
    " How do you define an array of 5 floats?",
    "A) float arr[5];", "B) arr[5] float;", "C) float[5] arr;", "D) float 5 arr[];",
    "A"
},
{
    " What is a key difference between arrays and pointers in C++?",
    "A) Arrays are static, while pointers are dynamic", "B) Arrays can store only integers, while pointers can store any data type", "C) Arrays and pointers are the same", "D) Pointers cannot be accessed by index",
    "A"
},
{
    " What will this code output? int arr[] = {10, 20, 30, 40}; cout << arr[3];",
    "A) 10", "B) 20", "C) 30", "D) 40",
    "D"
},
{
    " Which statement would correctly copy the first element of array arr1 to array arr2 in C++?",
    "A) arr2[0] = arr1[0];", "B) arr2 = arr1;", "C) arr2[1] = arr1[0];", "D) arr2 = arr[0];",
    "A"
}
            };
            int curscore = 0;
            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec7[random][0] << endl;
                cout << lec7[random][1] << endl;
                cout << lec7[random][2] << endl;
                cout << lec7[random][3] << endl;
                cout << lec7[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec7[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec7[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[6] = curscore;

            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }


        else if (topic == 8) {

            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;
            string lec8[15][6] = {
  {
      "How do you output a string using cout in C++?",
      "A) cout << string;", "B) cout.string();", "C) cout << \"string\";", "D) cout: print(string);",
      "C"
  },
  {
      " Which of the following is used to input a string from the user in C++?",
      "A) cin >> string;", "B) input(string);", "C) scanf(\"%s\", string);", "D) cin.get(string);",
      "A"
  },
  {
      " What does the getline() function do in C++?",
      "A) Reads a string from input until a newline is encountered", "B) Outputs a string to the screen", "C) Copies a string into another", "D) Reads an integer input",
      "A"
  },
  {
      " How can you find the length of a string in C++?",
      "A) string.length()", "B) length(string)", "C) strlen(string)", "D) str.length()",
      "A"
  },
  {
      " Which function is used to concatenate two strings in C++?",
      "A) concat()",
      "B) string.concat()",
      "C) str1.append(str2)",
      "D) str1 + str2",
      "D"
  },
  {
      " How do you compare two strings in C++?",
      "A) string1.compare(string2)", "B) string1 == string2", "C) string1 != string2", "D) Both A and B",
      "D"
  },
  {
      " What is an array of strings in C++?",
      "A) A two-dimensional array of characters", "B) A collection of multiple string variables", "C) A linked list of strings", "D) A string that holds multiple words",
      "B"
  },
  {
      " Which of these functions can be used to convert a string to uppercase in C++?",
      "A) toupper()", "B) toUpper()", "C) uppercase()", "D) toupper(string)",
      "A"
  },
  {
      " How do you open a file for input (read mode) in C++?",
      "A) ifstream file(\"file.txt\");", "B) file.open(\"file.txt\");", "C) fstream file(\"file.txt\");", "D) None of the above",
      "A"
  },
  {
      " What is the syntax to read a string from an input file?",
      "A) inputFile.read(str, 20);", "B) inputFile >> str;", "C) str >> inputFile;", "D) str.read(inputFile);",
      "B"
  },
  {
      " How do you open a file for output (write mode) in C++?",
      "A) ofstream file(\"file.txt\");", "B) file.open(\"file.txt\", ios::out);", "C) fstream file(\"file.txt\");", "D) Both A and B",
      "D"
  },
  {
      " Which statement is used to write to a file in C++?",
      "A) file >> string;", "B) file.put(string);", "C) file << string;", "D) file.write(string);",
      "C"
  },
  {
      " Which of these is used to check if a file was opened successfully in C++?",
      "A) file.is_open();", "B) file.open();", "C) file.status();", "D) file.checked();",
      "A"
  },
  {
      " What is the default mode for opening files in C++ if no mode is specified?",
      "A) read-only", "B) write-only", "C) append", "D) binary",
      "A"
  },
  {
      " What happens if you attempt to read from a file that does not exist in C++?",
      "A) A warning is displayed", "B) File contents are empty", "C) An error occurs", "D) The program hangs",
      "C"
  }
            };
            int curscore = 0;
            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec8[random][0] << endl;
                cout << lec8[random][1] << endl;
                cout << lec8[random][2] << endl;
                cout << lec8[random][3] << endl;
                cout << lec8[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec8[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec8[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[7] = curscore;


            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }


        else if (topic == 9) {

            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;
            string lec9[15][6] = {
  {
      " Which of the following is the correct syntax for declaring a structure in C++?",
      "A) struct Car { int speed; float weight; };", "B) structure Car { int speed; float weight; };", "C) struct Car(int speed, float weight) { };", "D) struct { int speed; float weight; };",
      "A"
  },
  {
      " How do you access the members of a structure in C++?",
      "A) .operator", "B) -> operator", "C) :: operator", "D) . and -> operators",
      "A"
  },
  {
      " Which of the following is the correct way to define a struct variable in C++?",
      "A) struct Car c;", "B) Car struct c;", "C) struct Car c = {100, 2000.5};", "D) Car c = struct(100, 2000.5);",
      "A"
  },
  {
      " What happens when you assign one struct variable to another in C++?",
      "A) The members are copied to the second struct", "B) Both struct variables point to the same memory location", "C) It causes a runtime error", "D) Only the first member is copied",
      "A"
  },
  {
      " Which statement correctly initializes a struct in C++?",
      "A) struct Car c = {100, 2000.5};", "B) Car c {100, 2000.5};", "C) struct c = {100, 2000.5};", "D) struct Car c {100, 2000.5};",
      "A"
  },
  {
      " What is the output of the following code: struct Car { int speed; float weight; }; Car c = {100, 2500.5}; cout << c.weight;?",
      "A) 100", "B) 2500.5", "C) 1002500.5", "D) Error",
      "B"
  },
  {
      " How do you define an enum type in C++?",
      "A) enum { RED, GREEN, BLUE };", "B) enum COLORS { RED, GREEN, BLUE };", "C) enum { RED = 1, GREEN = 2, BLUE = 3 };", "D) enum COLORS = {RED, GREEN, BLUE};",
      "B"
  },
  {
      " What is the output of the following code? enum Week {MON, TUE, WED}; cout << MON;",
      "A) MON", "B) 0", "C) Error", "D) 1",
      "B"
  },
  {
      " Which is the correct definition of a typedef in C++?",
      "A) typedef int Integer;", "B) typedef integer = int;", "C) typedef int Integer{};", "D) typedef(int) Integer;",
      "A"
  },
  {
      " What is the primary difference between enum and typedef?",
      "A) typedef defines data types, while enum defines constants", "B) typedef is for creating structures, while enum is used for constant values", "C) enum allows creating types, while typedef creates constants", "D) They perform the same function",
      "A"
  },
  {
      " Which of the following best describes a union in C++?",
      "A) A union holds multiple types but only one type can be stored at a time", "B) A union stores multiple types at once", "C) A union is the same as a struct but with less memory", "D) A union is a type of array",
      "A"
  },
  {
      " How do you declare a union in C++?",
      "A) union { int i; float f; };", "B) union data { int i; float f; };", "C) union data int i, float f;", "D) Both A and B are correct",
      "D"
  },
  {
      " In a union, how much memory is used by the largest member?",
      "A) Memory equal to the size of the largest member", "B) Memory equal to the sum of all member sizes", "C) Memory equal to the average size of all members", "D) No memory is used by a union",
      "A"
  },
  {
      " How would you define an array of structs in C++?",
      "A) struct Car cars[10];", "B) struct Car[10] cars;", "C) struct[] cars; ", "D) Array cars[10];",
      "A"
  },
  {
      "What will this code print if Car cars[2]; cars[0].speed = 100; cout << cars[0].speed;?",
      "A) 100", "B) cars[0].speed", "C) Error", "D) 0",
      "A"
  }
            };
            int curscore = 0;
            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;
                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec9[random][0] << endl;
                cout << lec9[random][1] << endl;
                cout << lec9[random][2] << endl;
                cout << lec9[random][3] << endl;
                cout << lec9[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec9[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec9[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[8] = curscore;

            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }


        else if (topic == 10) {

            int curscore = 0;
            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;
            string lec10[15][6] = {
  {
      " What is the correct syntax for declaring a pointer to an integer in C++?",
      "A) int* ptr;", "B) pointer int;", "C) int ptr*;", "D) int& ptr;",
      "A"
  },
  {
      " Which of the following is used to dereference a pointer in C++?",
      "A) &", "B) *", "C) ->", "D) .",
      "B"
  },
  {
      " What is the output of the following code: int x = 10; int* ptr = &x; cout << *ptr;?",
      "A) 10", "B) Address of x", "C) ptr", "D) Error",
      "A"
  },
  {
      " In C++, what does the & operator do?",
      "A) Dereferences a pointer", "B) Defines a reference", "C) Accesses a pointer's address", "D) Gets the value stored at a memory address",
      "C"
  },
  {
      " Which of the following will correctly print the address of a variable x?",
      "A) cout << x;", "B) cout << &x;", "C) cout << &x;", "D) cout << x;",
      "B"
  },
  {
      " What is the correct way to declare a pointer to a string in C++?",
      "A) string* ptr;", "B) string ptr*;", "C) string& ptr;", "D) ptr string*;",
      "A"
  },
  {
      " What will be the output of the following code: int arr[3] = {1, 2, 3}; int* ptr = arr; cout << *(ptr + 1);?",
      "A) 1", "B) 2", "C) 3", "D) Error",
      "B"
  },
  {
      " What is pointer arithmetic in C++?",
      "A) Changing the value of a pointer directly", "B) Changing the pointer type", "C) Moving the pointer to the next memory location of the data type", "D) Accessing a pointer's value",
      "C"
  },
  {
      " What will be printed by the following code: int x = 10; int* ptr = &x; *ptr = 20; cout << x;?",
      "A) 10", "B) 20", "C) ptr", "D) Address of x",
      "B"
  },
  {
      " Which of the following types cannot be used as a pointer in C++?",
      "A) int*", "B) float*", "C) char*", "D) string*",
      "D"
  },
  {
      " What does the sizeof operator return when used on a pointer?",
      "A) The size of the data type pointed to", "B) The size of the pointer itself", "C) The number of elements in an array", "D) The address of the pointer",
      "B"
  },
  {
      " How do you declare a pointer to a function in C++?",
      "A) int* (ptr)();", "B) int ptr();", "C) int (ptr)();", "D) ptr int();",
      "C"
  },
  {
      " What will be printed by the following code: int* ptr = nullptr; cout << ptr;?",
      "A) 0", "B) Null", "C) Address of ptr", "D) Error",
      "A"
  },
  {
      " What is the main advantage of using pointers in C++?",
      "A) It allows for efficient memory management", "B) It allows modifying constant variables", "C) It makes variable names shorter", "D) It automatically frees up memory",
      "A"
  },
  {
      " What is the correct syntax to pass a pointer to a function in C++?",
      "A) function(int* ptr);", "B) function(int& ptr);", "C) function(int ptr*);", "D) function(ptr);",
      "A"
  }
            };
            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << lec10[random][0] << endl;
                cout << lec10[random][1] << endl;
                cout << lec10[random][2] << endl;
                cout << lec10[random][3] << endl;
                cout << lec10[random][4] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (lec10[random][5][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << lec10[random][5] << endl;

                }
                cout << "\n----------------------------------------------\n";
            }
            currentplayer.Mcq_TopicsScore[9] = curscore;

            cout << "You scored in this chapter: " << curscore << endl;
            cout << "Your total score: " << score;

        }

        else if (topic == 11) {

            int curscore = 0;
            do {
                cout << "\nEnter how many questions you want (1-15): ";

                if (!(cin >> quesnum)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                    continue;
                }

                if (quesnum < 1 || quesnum > 15) {
                    cout << "Invalid number! Please enter a value between 1 and 15.\n";
                }
            } while (quesnum < 1 || quesnum > 15);


            cout << endl;
            string questions[34][5] = {
 {"Which of the following initializes an array in C++?", "int arr[5] = {1, 2, 3, 4, 5};", "int arr = {1, 2, 3, 4, 5};", "int arr[5] = new {1, 2, 3, 4, 5};", "A"},
 {"How do you declare a pointer in C++?", "int ptr;", "pointer int ptr;", "int ptr;", "C"},
 {"What is the size of a basic char data type in C++?", "1 byte", "2 bytes", "4 bytes", "B"},
 {"Which loop is used to repeat a block of code a set number of times?", "for", "while", "do-while", "A"},
 {"Which condition statement checks multiple conditions in C++?", "if-else", "switch", "while", "B"},
 {"What is the correct syntax for a switch statement?", "switch(expression) { case x: statement; break; }", "switch(expression) { if(x) statement; }", "switch { expression }", "C"},
 {"How would you declare a basic structure in C++?", "struct Person { int age; };", "struct { int age; };", "class Person { int age; };", "A"},
 {"How can you initialize a C++ array of integers with size 5?", "int arr[5] = {0};", "int arr = [0, 0, 0, 0, 0];", "int arr[5] {0};", "C"},
 {"What keyword is used to return a value from a function?", "return", "yield", "exit", "A"},
 {"How do you declare a function to calculate sum in C++?", "int sum(int a, int b) { return a + b; }", "int sum a, b { return a + b; }", "function int sum(a, b) { return a + b; }", "A"},
 {"Which operator dereferences a pointer in C++?", "*", "&", "-", "A"},
 {"What is the default value of an uninitialized pointer in C++?", "null", "0", "undefined", "B"},
 {"Which of the following correctly defines an array of pointers in C++?", "int* arr[10];", "int arr[10];", "int** arr[10];", "A"},
 {"Which of these loops is guaranteed to execute at least once?", "do-while", "for", "while", "B"},
 {"What does the 'continue' keyword do in a loop?", "It skips the current iteration and moves to the next iteration", "It breaks out of the loop", "It ends the program", "C"},
 {"Which keyword is used to allocate memory for an array dynamically in C++?", "new", "malloc", "calloc", "A"},
 {"What is a reference variable in C++?", "An alias for another variable", "A second copy of a variable", "A pointer to another variable", "A"},
 {"How do you declare an array of 10 integers?", "int arr[10];", "int arr = new int[10];", "array int[10];", "C"},
 {"Which C++ function is used to find the length of a string?", "strlen", "length", "str_length", "A"},
 {"What is the purpose of the const keyword in C++?", "To make a variable immutable", "To allow the variable to change", "To declare a pointer", "B"},
 {"Which of the following functions will read a string from input in C++?", "cin.getline(str, size)", "getline(cin, str)", "cin >> str", "B"},
 {"How do you call a function from the main function?", "sum(a, b);", "int sum(int a, b);", "void sum(a, b);", "C"},
 {"What is a struct in C++?", "A collection of data variables that can be of different types", "A special kind of array", "A class with no members", "A"},
 {"Which operator is used to assign a value to a pointer?", "=", "*", "&", "B"},
 {"Which of the following is NOT a valid function type in C++?", "void", "string", "int[]", "C"},
 {"What is the role of a destructor in C++?", "To clean up resources when an object goes out of scope", "To initialize variables", "To update member variables", "A"},
 {"Which operator would you use to access a member of a structure via a pointer?", "->", ".", "::", "A"},
 {"What type of loop should be used to iterate over an array until a condition is met in C++?", "for", "while", "do-while", "B"},
 {"Which of the following is an invalid function signature in C++?", "void func(int a, int b);", "void func(int a);", "void int func(int a, int b);", "C"},
 {"What is a valid pointer declaration for an integer pointer in C++?", "int *ptr;", "pointer ptr;", "ptr *int;", "A"},
 {"Which of the following operators is used to compare equality in C++?", "==", "=", "===", "B"},
 {"How would you return a string from a function in C++?", "return str;", "return (str);", "return string(str);", "C"},
 {"What will this code print: int a = 5; cout << a++;?", "5", "6", "Error", "A"},
 {"Which C++ keyword is used to declare a constant value?", "const", "final", "static", "A"}
            };


            bool askedQuestions[15] = { false };
            bool* ptrAskedQuestions = askedQuestions;

            for (int i = 0; i < quesnum; ++i) {
                int random;

                do {
                    random = 15 - (rand() % 15);
                } while (*(ptrAskedQuestions + random));

                *(ptrAskedQuestions + random) = true;

                cout << endl;
                cout << "Qustion " << i + 1 << " :" << questions[random][0] << endl;
                cout << "A)" << questions[random][1] << endl;
                cout << "B)" << questions[random][2] << endl;
                cout << "C)" << questions[random][3] << endl;



                char answer;
                cout << "Enter your choice (A-D): ";
                cin >> answer;
                cout << endl;
                answer = toupper(answer);

                if (answer == (questions[random][4][0])) {
                    cout << "Correct answer :)" << endl;
                    score += 1;
                    curscore += 1;

                }
                else {
                    cout << "Wrong! The correct answer is option " << questions[random][4] << endl;

                }
                cout << "\n----------------------------------------------\n";

            }
            currentplayer.Mcq_TopicsScore[10] = curscore;

            cout << "You scored in this chapter: " << currentplayer.Mcq_TopicsScore[10] << endl;
            cout << "Your total score: " << score;


        }









        do {
            cout << "\nDo you want to repeat MCQ questions (Y / N) ? ";
            cin >> choice;
            choice = tolower(choice);

            if (cin.fail() || !isalpha(choice) || (choice != 'y' && choice != 'n')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter 'y' or 'n':\n ";
            }
        } while (cin.fail() || !isalpha(choice) || (choice != 'y' && choice != 'n'));



    } while (choice == 'y');
    int top3scoresarr[3] = { 0 };

    displaygraph(currentplayer.Mcq_TopicsScore);

    top3scores(currentplayer.Mcq_TopicsScore, top3scoresarr);
    displaytop3scores(top3scoresarr);





}

//TFQ FUNCTIONS.
void DisplayQuestions(TFQA questions[], int& size) {
    int countscore = 0;
    system("cls");
    srand(time(0));

    int cheek[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    for (int i = 0; i < size; i++) {
        int randques = rand() % 15;
        while (cheek[randques] == 1)
            randques = rand() % 15;


        if (cheek[randques] == 0) {
            cout << i + 1 << ". " << questions[randques].question << " (Y/N): ";
            char userAnswer;
            cin >> userAnswer;
            userAnswer = toupper(userAnswer);
            bool userBool = (userAnswer == 'Y');
            if (userBool == questions[randques].answer) {
                cout << "Correct answer :)!\n";
                countscore += 1;
                score += 1;
            }
            else {
                cout << "Wrong!, but good try \n";
            }
            cheek[randques] = 1;
        }

    }
    currentplayer.TF_TopicsScore[currentTopic - 1] = countscore;
    cout << "\n\nyour score in this chapter is: " << currentplayer.TF_TopicsScore[currentTopic - 1] << endl;
    cout << "\nyour total score is: " << score << endl;
}
void loadTFData(TFQA qas[15]) {
    ifstream file("tf_questions.txt");
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    int qIndex = 0;

    // Read each line of the file
    while (getline(file, line)) {
        int topic = 0;
        string question = "";
        string answerStr = "";

        // Find the first '|' (pipe) to split topic number and the rest of the line
        int firstPipe = line.find('|');
        if (firstPipe != string::npos) {
            topic = stoi(line.substr(0, firstPipe));  // Extract the topic number
            line = line.substr(firstPipe + 1);  // Remove the topic number from the line
        }

        // Check if this line corresponds to the selected topic
        if (topic == currentTopic) {
            // Find the second '|' to separate question from answer
            int secondPipe = line.find('|');
            if (secondPipe != string::npos) {
                question = line.substr(0, secondPipe);  // Extract the question
                answerStr = line.substr(secondPipe + 1);  // Extract the answer
            }

            // Convert the answer string to boolean
            bool answer = (answerStr == "1");

            // Store the question-answer pair in the array if there is room
            if (qIndex < 15) {
                qas[qIndex] = { question, answer };
                qIndex++;

            }
            else if (qIndex >= 15)
                return;
        }
    }

    file.close();
}
void TrueFalseQuestionsScreen()




{
    score=0;
    int topic;
    char repeat;
    int quesnum;
    int top3scoresarr[3];
    string topics[11] = { "Introduction to Computer & Programming", "Problem Solving", "Basic Elements of C++",
                          "Selection Control Structure", "Repetition Control Structure", "Function",
                          "Array", "String & File", "Structured Data", "Pointer","Mix questions" };

    int size = sizeof(topics) / sizeof(topics[0]);
    do {
        system("cls");

        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << topics[i] << endl;
        }



        cout << "Enter the topic number you want to test yourself in (1-11): ";
        cin >> topic;


        while (topic < 1 || topic > 11) {
            cout << "Invalid topic number. Please try again: \n";
            cin >> topic;
        }

        TFQA qas[15];

        switch (topic) {
        case 1:
            currentTopic = 1;
            loadTFData(qas);
            break;



        case 2:
            currentTopic = 2;
            loadTFData(qas);
            break;

        case 3:
            currentTopic = 3;
            loadTFData(qas);
            break;

        case 4:
            currentTopic = 4;
            loadTFData(qas);
            break;

        case 5:
            currentTopic = 5;
            loadTFData(qas);
            break;

        case 6:
            currentTopic = 6;
            loadTFData(qas);
            break;

        case 7:
            currentTopic = 7;
            loadTFData(qas);
            break;
        case 8:
            currentTopic = 8;

            loadTFData(qas);

            break;
        case 9:
            currentTopic = 9;
            loadTFData(qas);
            break;

        case 10:
            currentTopic = 10;
            loadTFData(qas);
            break;

        case 11:
            currentTopic = 11;
            loadTFData(qas);
            break;





        default:
            cout << "Invalid topic selection. Please try again.\n";
            break;
        }

        do {
            cout << "\nEnter how many questions you want (1-15): ";

            if (!(cin >> quesnum)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid number between 1 and 15.\n";
                continue;
            }

            if (quesnum < 1 || quesnum > 15) {
                cout << "Invalid number! Please enter a value between 1 and 15.\n";
            }
        } while (quesnum < 1 || quesnum > 15);

        DisplayQuestions(qas, quesnum);

        do {
            cout << "\nDo you want to repeat True and False questions (Y / N) ? ";
            cin >> repeat;
            repeat = tolower(repeat);

            if (cin.fail() || !isalpha(repeat) || (repeat != 'y' && repeat != 'n')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter 'y' or 'n':\n ";
            }
        } while (cin.fail() || !isalpha(repeat) || (repeat != 'y' && repeat != 'n'));



    } while (repeat == 'y');
    int top3scoresarray[3] = { 0,0,0 };
    displaygraph(currentplayer.TF_TopicsScore);
    top3scores(currentplayer.TF_TopicsScore, top3scoresarray);
    displaytop3scores(top3scoresarray);
}

//HANDLING FILES.
void exportPlayerToFile(const player player, const string filename = "players_history.txt") {
    fstream outFile(filename, ios::app); // Open file in append mode
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    // Write player data
    outFile << "--------------------------------------\n";
    outFile << "Player Name: " << player.name << endl;
    outFile << "Multiple-Choice Topics Scores:" << endl;
    for (int i = 0; i < 11; ++i) {
        outFile << "Topic " << setw(2) << i + 1 << ": " << player.Mcq_TopicsScore[i] << endl;
    }

    outFile << "True/False Topics Scores:" << endl;
    for (int i = 0; i < 11; ++i) {
        outFile << "Topic " << setw(2) << i + 1 << ": " << player.TF_TopicsScore[i] << endl;
    }
    outFile << "--------------------------------------\n";

    outFile.close();
    cout << "Player data exported successfully to " << filename << "!" << endl;
}
void Showhistoryscreen(string filename = "players_history.txt") {

    system("cls");
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    cout << "\nAll Players Data:\n";
    cout << "--------------------------------------\n";

    while (getline(inFile, line)) {
        if (line == "--------------------------------------") {
            cout << "--------------------------------------\n";
        }
        else {
            cout << line << endl;
        }
    }

    inFile.close();

}
void savefeedbacks() {

    ofstream writeto("feedbacks.txt", ios::out | ios::app);

    if (!writeto) {
        cout << "Error with opening file.";
    }
    else {

        writeto << fb.note.name << endl;


    }

    writeto.close();
}

//QUIZZ SCREEN.
void quizmainscreen() {
    short choice;
    char answer;
    
    cout << "Enter your name: ";

    getline(cin, currentplayer.name);
    
    system("cls");
    cout << setw(10) << "" << "___________________________________________________________\n\n";
    cout << setw(20) << "" << "Welcome " << currentplayer.name << " to the C++ Quiz App\n\n";
    cout << setw(10) << "" << "___________________________________________________________\n\n";
    cout << setw(35) << "\n\n\n\nPress any key to continue.";
    system("pause>0");


    do {
        system("cls");

        cout << setw(20) << "" << "_________________________________________\n\n";
        cout << setw(20) << "" << "Choose the type of questions you want:\n\n";
        cout << setw(20) << "" << "_________________________________________\n\n";

        cout << setw(20) << "" << "[1]: Multiple-choice questions\n";
        cout << setw(20) << "" << "[2]: True/False questions\n";
        cout << setw(20) << "" << "[3]: showe players history\n\n\n";




        do {

            cout << "Choose an option [1-3]: ";


            if (cin >> choice) {
                if (choice > 0 && choice <= 3) {
                    break;
                }
                else {
                    cout << "\nInvalid input. Please enter a valid option [1-3]: ";
                }
            }
            else {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter a valid option [1-3]: ";
            }
        } while (true);

        switch (choice) {
        case 1:
            MultiQuestionsScreen();
            break;
        case 2:
            TrueFalseQuestionsScreen();
            break;
        case 3:
            Showhistoryscreen();
            break;


        }



        do {
            cout << "Do you want to continue the quiz? (y/n): ";
            cin >> answer;
            answer = tolower(answer);

            if (cin.fail() || !isalpha(answer) || (answer != 'y' && answer != 'n')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter 'y' or 'n':\n ";
            }
        } while (cin.fail() || !isalpha(answer) || (answer != 'y' && answer != 'n'));




    } while (answer == 'y');

    exportPlayerToFile(currentplayer);

    cout << "\n\nPlease give your feedback about our app :) or (press enter to terminate...)\n";
    cin.ignore();
    getline(cin, fb.note.name);



    if (fb.note.name.empty()) {

        exit(0);
    }
    else {
        cout << "Thank you for your feedback :)";
    }
    savefeedbacks();
}

int main()
{
    quizmainscreen();

    return 0;
}

