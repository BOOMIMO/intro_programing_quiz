#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4
#define TIME_LIMIT 1800 // 30 minutes in seconds

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][100];
    char answer;
} QuizQuestion;

void initializeQuestions(QuizQuestion quiz[]) {
    strcpy(quiz[0].question, "What is a programming language?");
    strcpy(quiz[0].options[0], "A) A tool for writing music");
    strcpy(quiz[0].options[1], "B) A set of instructions for a computer");
    strcpy(quiz[0].options[2], "C) A type of hardware");
    strcpy(quiz[0].options[3], "D) A database management system");
    quiz[0].answer = 'B';

    strcpy(quiz[1].question, "Which of the following is NOT a programming language?");
    strcpy(quiz[1].options[0], "A) Python");
    strcpy(quiz[1].options[1], "B) Java");
    strcpy(quiz[1].options[2], "C) HTML");
    strcpy(quiz[1].options[3], "D) C++");
    quiz[1].answer = 'C';

    strcpy(quiz[2].question, "What does 'compilation' mean?");
    strcpy(quiz[2].options[0], "A) Running a program directly");
    strcpy(quiz[2].options[1], "B) Converting source code into machine code");
    strcpy(quiz[2].options[2], "C) Debugging a program");
    strcpy(quiz[2].options[3], "D) Writing code in an IDE");
    quiz[2].answer = 'B';

    strcpy(quiz[3].question, "What is an algorithm?");
    strcpy(quiz[3].options[0], "A) A type of programming language");
    strcpy(quiz[3].options[1], "B) A step-by-step procedure for solving a problem");
    strcpy(quiz[3].options[2], "C) A command used in coding");
    strcpy(quiz[3].options[3], "D) A software application");
    quiz[3].answer = 'B';

    strcpy(quiz[4].question, "Which of the following is a common use of programming?");
    strcpy(quiz[4].options[0], "A) Writing novels");
    strcpy(quiz[4].options[1], "B) Creating websites and applications");
    strcpy(quiz[4].options[2], "C) Painting artworks");
    strcpy(quiz[4].options[3], "D) Conducting scientific experiments");
    quiz[4].answer = 'B';
}

void displayQuestion(const QuizQuestion* q, int questionNumber) {
    printf("Question %d: %s\n", questionNumber + 1, q->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%s\n", q->options[i]);
    }
}

int main() {
    QuizQuestion quiz[MAX_QUESTIONS];
    int score = 0;
    char userAnswers[MAX_QUESTIONS];
    
    initializeQuestions(quiz);

    time_t startTime = time(NULL);
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(&quiz[i], i);
        char userAnswer;
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &userAnswer);
        
        userAnswers[i] = userAnswer; // Store user's answer
        
        if (userAnswer == quiz[i].answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c.\n\n", quiz[i].answer);
        }

        // Check if time limit has been reached
        if (difftime(time(NULL), startTime) >= TIME_LIMIT) {
            printf("Time's up! You have exceeded the time limit.\n");
            break;
        }
    }

    // Final results
    printf("Your final score: %d out of %d\n", score, MAX_QUESTIONS);
    
    // Provide feedback on incorrect answers
    printf("\nReview of your answers:\n");
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (userAnswers[i] != quiz[i].answer) {
            printf("Question %d: Your answer was %c. Correct answer is %c.\n", 
                   i + 1, userAnswers[i], quiz[i].answer);
        }
    }

    return 0;
}