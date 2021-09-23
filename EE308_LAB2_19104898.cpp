#include <string>
#include<iostream>
#include<fstream>
#include<regex>
using namespace std;
int main(){
    int num=0,num1=0,num2=0,num3=0,num4=0,num5=0,x=0;
    ifstream inFile("/Users/jackson/Desktop/Text.txt");
    string s;
    string s1[100];
   string  key[32]={"auto","short","int","long","float","double","char","struct","union","enum","typedef","const","unsigned","signed","extern","register","static","volatile","void","if","else","switch","case","for","do","while","goto","continue","break","default","sizeof","return"};
    while(getline(inFile,s)){
        
    for(int i=0;i<32;i++){
        regex e(key[i]);
        bool match=regex_search(s,e);
        if(match==true){
            num++;
        }
    }
        regex e("switch");
        regex e3("default");
        bool match=regex_search(s,e);
        bool match3=regex_search(s,e3);
        if(match==true){
            num1++;
            x++;
        }else if(x!=0&&match==false){
            if(match3==true){
                s1[x]=s;
                x++;
            }
            s1[x]=s;
            x++;
        }
        regex e1("else");
        
        bool match1=regex_search(s,e1);
       // bool match2=regex_search(s,e2);
        if(match1==true){
                num3++;
        }
    }
     cout<<"Total num: "<<num<<endl;
     cout<<"switch num: "<<num1<<endl;
    cout<<"case num: ";
     for(int i=0;i<100;i++){
            regex e1("case");
        regex e2("default");
             bool match1=regex_search(s1[i],e1);
             bool match2=regex_search(s1[i],e2);
             if(match1==true){
                 num2++;
             }if(match2==true){
                 if(num2!=0){
                     cout<<num2<<" ";
                 }
                 num2=0;
             }
          
    }cout<<endl;
        
    
   // cout<<num2<<" ";
    /*for(int i=0;i<2;i++){
        if(arr[i]!=0){
            cout<<arr[i]<<" ";
        }
    }*/
     inFile.close();
                           }
    
