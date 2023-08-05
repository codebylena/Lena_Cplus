// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    double exam = 0.0;
    int examnum = 0;

    double finalExam = 0.0;

    double hw = 0.0;
    int hwnum = 0;
    
    double lw = 0.0;
    int lwnum = 0;

    double reading = 0.0;
    int readingnum = 0;

    double engagement = 0.0;
    int engagementnum = 0;

    double programCheck = 0.0;

   
    


    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score

            exam = exam + score;
            ++examnum;
            

        } else if (category == "final-exam") {
            // TODO(student): process final score
            finalExam = score;
            ++examnum;

        } else if (category == "hw") {
            // TODO(student): process hw score
            hw = hw + score;
            ++hwnum;

        } else if (category == "lw") {
            // TODO(student): process lw score
              
            if(score == 1){
                lw = lw + 100;
                ++lwnum;
            }
            else {
                  ++lwnum;
      
            }
        } else if (category == "reading") {
            // TODO(student): process reading score
            reading = reading + score;
            ++readingnum;
            

        } else if (category == "engagement") {
            // TODO(student): process engagement score
            engagement = engagement + score;
            ++engagementnum;
    
        }else if  (category == "program-check") {
            // TODO(student): process program-check score

            if(score == 1){
                ++programCheck;
            }
            else { }
            

        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
    double  exam_average;
    double hw_average;
    double lw_average;
    double reading_average;
    double engagement_average;

  
  
  
   if (examnum == 0){
       exam_average = 0.0;
    }
   
     
    else{

    exam_average =((exam + finalExam)/ 3);
 }
// if final is greater than average
 if (finalExam > exam_average){

exam_average = finalExam;

 }
    else {}


    if (hwnum == 0){
        hw_average = 0.0;
    }

    else {

    hw_average = hw / hwnum;
    }
    
    if (lwnum == 0){
        lw_average = 0;
    }
    else{

        if(programCheck == 2.0){
                lw_average = lw / lwnum;
        }

        else if (programCheck == 1.0){
                lw_average = (lw / lwnum) * 0.75;
        }

        else {

                lw_average = (lw / lwnum) * 0.5;
                
        }

    }

    if (readingnum == 0){
        reading_average = 15.0;
    }
    
    else if (((reading / readingnum) + 15.0) >= 100){
        reading_average = 100.0;
    }

    else{
    reading_average = (reading / readingnum) + 15.0;

    }

    if (engagementnum == 0){
        engagement_average = 15.0;
    }

    else if (((engagement / engagementnum) + 15.0) >= 100){
        engagement_average = 100.0;
    }

    else{
    engagement_average = (engagement / engagementnum) + 15.0;

    }

   
    

    // TODO(student): compute weighted total of components
    double weighted_total = ((exam_average/ 100) * 40.0) + ((hw_average / 100) * 40.0) + ((lw_average) / 100 * 10.0) + ((reading_average /100) * 5.0) + ((engagement_average/100) * 5.0);

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if(weighted_total >= 90){
        final_letter_grade = 'A';
    }
    else if(weighted_total >=80){
        final_letter_grade = 'B';
    }
    else if(weighted_total >= 70){
        final_letter_grade = 'C';
    }
    else if(weighted_total >= 60){
        final_letter_grade = 'D';
    }
    else{
        final_letter_grade = 'F';
    }

    print_results(
        exam_average, hw_average, lw_average, reading_average, engagement_average,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement | program-check" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
