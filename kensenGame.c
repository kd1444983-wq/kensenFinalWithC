#include <stdio.h>
#include <time.h>
#include <stdlib.h>

 int operation(int number1,int number2, char operator);

int main(){
    
     srand((unsigned int)time(NULL));
    int i = 0;
    int myAnswer = 0;
    int score =0;
    double average =0;
    double averageTime =0;
    printf("計算ゲームを始めます。\n");

      // startGame
    time_t start_time = time(NULL);
    for(i = 0 ;i < 5 ; i++){
   
    int randomNumber1= 1+ (rand() % 70);
    int randomNumber2= 1 + (rand() % 70);

    char operatorArray[4] = {'+','-','*','/'};
    int arraySize = sizeof(operatorArray)/sizeof(operatorArray[0]);
    int randomOperator = rand() % arraySize;
    char charOperator;

    switch(randomOperator){
        case 1:
           charOperator ='+';
            break;
        case 2:
          charOperator ='-';
        break;
        case 3:
            charOperator ='*';
        break;
        default:
            charOperator ='/';
        break;

    }

        printf("第%d問:%d%c%d=",i+1,randomNumber1,charOperator,randomNumber2);
        scanf("%d",&myAnswer);
        int realAnswer =operation(randomNumber1,randomNumber2,charOperator);


        if(myAnswer==realAnswer) {
            score++;
            printf("your answer is correct!\n");
        }else{
            printf("you answer is not correct\n");
        }

    }

    // END GAME
    time_t end_time = time(NULL);
    double totalTime = difftime(end_time,start_time);

    averageTime = totalTime / 5 ;
    /*ဂဏန်းနှစ်ခုလုံးက ကိန်းပြည့် (int) ဖြစ်နေပါက အစားတွက်ချက်ရာတွင် 0 ထွက်သွားတတ်သဖြင့် double သို့မဟုတ် float ပြောင်းပေးရန် လိုအပ်ပါတယ်။*/

    printf("###Your result###\n");
    printf("your total score %d/5\n",score);

    average = ((double)score/i) * 100.0; 
    printf("your total average %.1f%%\n",average);
    
    //end game
    printf("your time is:%.0f second\n",averageTime);
   



    return 0;
}

 int operation(int number1,int number2, char operator)
{
    int realAnswer =0;

    switch(operator){
        case '+':
         realAnswer = number1 + number2;
         break;
         case '-':
         realAnswer = number1-number2;
         break;
         case '*':
         realAnswer = number1*number2;
         break;
        default:
         realAnswer = number1/number2;
         break;
    }

    return realAnswer;


            
            
}