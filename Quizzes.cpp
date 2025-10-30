#include <iostream>
#include <vector>

using namespace std;

//In-Progress
//class Question{
    //private:
        //string QuestionName;
        //vector<string> question;
        //char Anwser;
    //public:
        //Question(string QuestionName, vector<string> question, char Anwser) {
            //this->QuestionName = QuestionName;
            //this->question = question;
            //this->Anwser = Anwser;
        //}

        //string PrintQuestion(string question) {
            //for(auto& opt : question){
                //char letter = 'A';
                //cout << letter << "." << opt << "\n";
                //letter++;
            //}
        //}

        // void CheckAnwser(char UserInput){
        //     for(int i = 0; i < 3; i++){
        //     return toupper(Anwser) == UserInput;
        // }
        // }

//};

//class Quiz{
    //private:
        //string name;
        //vector<Question> questions;
    //public:
        //string GetName() {
            //return name;
        //}

        

//};

//Working Code

int main() {
    string QuizQuestions[] = {
        {"Czy ziemia jest plaska?"},
        {"Jaka jest stolica Polski?"},
        {"Ile wynosi pierwiastek z 36"}
    };
    string PossibleAnwser[][3] = {
        {"tak", "nie", "moze"},
        {"Warszawa", "Paryz", "Moskwa"},
        {"9", "7", "6"}
    };
    char CorrectAnwser[] = {'B','A','C'};
    char anwser;
    int score = 0;
    int incorrscore = 0;

    for(int i = 0; i < 3; i++){
        cout << "Pytanie "<< i + 1 << " " << QuizQuestions[i] << "\n";;
        cout << "A." << PossibleAnwser[i][0] << "\nB." << PossibleAnwser[i][1] << "\nC." << PossibleAnwser[i][2] << "\n>> ";
        cin >> anwser;

        if(toupper(anwser) == CorrectAnwser[i]) {
            cout << "Odpowiedziales poprawnie!\n";
            score++;
        }else {
            cout << "Bledna odpowiedz!\n";
            cout << "Poprawna odpowiedz to: " << CorrectAnwser[i] << "\n";
            incorrscore++;
        }
    }
    int allquestions = score + incorrscore;

    cout << "Wyniki Tego Quizu:\n";
    cout << "Ilosc wszystkich pytan: " << allquestions << "\n";
    cout << "Poprawne odpowiedzi: " << score << "\n";
    cout << "Procenty: " << ((double)score / (double)allquestions) *  100 << "%\n";

}
