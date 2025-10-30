#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question{
    private:
        string QuestionName;
        vector<string> question;
        char Anwser;
    public:
        Question(string QuestionName, vector<string> question, char Anwser) {
            this->QuestionName = QuestionName;
            this->question = question;
            this->Anwser = toupper(Anwser);
        }

        string GetQuestionName() {
            return QuestionName;
        }

        vector<string> GetQuestion() {
            return question;
        }

        string PrintQuestion(int i) {
            cout << "\nPytanie " << i + 1 << ": " << QuestionName << "\n";
            char letter = 'A';
            for(auto& opt : question){
                cout << letter << ". " << opt << "\n";
                letter++;
            }
        }

        bool CheckAnwser(char ans){
            return Anwser == toupper(ans);
        }
};

class Quiz{
    private:
        string name;
        vector<Question> questions;
    public:
        string GetName() {
            return name;
        }

        Quiz(string name) : name(name) {}

        void AddQuestion() {
            string QuestionName;
            vector<string> question(3);
            char UserInput;
            char letter = 'A';

            cout << "Jakie Chcesz dodac pytanie do quizu?\n>> ";
            getline(cin, QuestionName);
            if(QuestionName == ""){
                getline(cin, QuestionName);
            }
            cout << endl;


            cout << "Podaj 3 mozliwe odpowiedzi: \n";
            for(int i = 0; i < 3; i++){
                cout << letter << ": ";
                getline(cin, question[i]);
                letter++;
            }
            cout << "Podaj Poprawna odpowiedz na to pytanie\n>> ";
            cin >> UserInput;

            Question NewQuestion(QuestionName, question, UserInput);
            questions.push_back(NewQuestion);
            cout << "Udalo sie dodac pytanie do quizu!\n";
        }

        void StartQuiz() {
            if(questions.empty()){
                cout << "Nie ma zadnego dostepnego quizu!";
            }
            int score = 0;
            for(int i = 0; i < questions.size(); i++){
                questions[i].PrintQuestion(i);

                char ans;
                cout << "Podaj Odpowiedz: \n>> ";
                cin >> ans;
                
                if(questions[i].CheckAnwser(ans)){
                    cout << "Poprawna odpowiedz!\n";
                    score++;
                }else {
                    cout << "Niepoprawna odpowiedz\n";
                }

                cout << "Ilosc zebranych punktow: " << score << "\n";
                cout << "Procenty" << (score / questions.size()) * 100;
                    }
        }
};

    class QuizManager {
        private:
            vector<Quiz> quizzes;
        public:
            void NewQuiz(){
                string QuizName, QuestionName, question;
                char ans;
                int num;

                cout << "Podaj nazwe quizu: \n>> ";
                getline(cin, QuizName);
                Quiz NewQuiz(QuizName);

                cout << "Ile chcesz dodac pytan?: \n>> ";
                cin >> num;
                for(int i = 0; i < num; i++){
                    cout << "Dodaj pytanie " << i + 1 << endl;
                    NewQuiz.AddQuestion();
                }
                quizzes.push_back(NewQuiz);
                cout << "Pomyslnie dodano quiz\n";
            }

            void AddQuestionToExistingQuiz() {
                string name;
                cout << "podaj nazwe quizu do ktorego chcesz dodac pytanie: \n>> ";
                getline(cin, name);

                for(auto& quiz : quizzes){
                    if(quiz.GetName() == name){
                        quiz.AddQuestion();
                    }
                }

                cout << "Nie ma takiego quizu!\n";
            }

            void StartExistingQuiz() {
                cout << "Dostepne Quizy: \n";
                for(int i = 0; i < quizzes.size(); i++){
                    cout << i + 1 << ". " << quizzes[i].GetName() << endl;
                }

                int wybor;
                cout << "Ktory quiz wybierasz: \n>> ";
                cin >> wybor;

                if(wybor >= 1 && wybor <= quizzes.size()){ 
                    quizzes[wybor - 1].StartQuiz();
                }

            }
    };

int main() {
    QuizManager quizmanager;

    int wybor;
    bool program = true;

    while(program) {
        cout << "----------------Quizzes---------------\n";
        cout << "Co Chcesz Zrobic: \n";
        cout << "1.Dodac Nowy Quiz.\n";
        cout << "2.Dodac Pytanie Do Istniejacego Quizu.\n";
        cout << "3.Zaczac Istniejacy Quiz.\n";
        cout << "4.Zakonczyc Program.\n";
        cout << "--------------------------------------\n>> ";
        cin >> wybor;

        switch(wybor) {
            case 1:
                quizmanager.NewQuiz();
            break;
            case 2:
                quizmanager.AddQuestionToExistingQuiz();
            break;
            case 3:
                quizmanager.StartExistingQuiz();
            break;
            case 4:
                program = false;
            break;
            default:
                cout << "Nie poprawny wybor!\n";
            break;
        }
    }
}
