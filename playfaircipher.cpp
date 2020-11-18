#include <iostream>
using namespace std;
bool isUpperCase(char a){
    if(a<=90&&a>=65){
        return true;
    }
    return false;
}

bool isAlphabet(char a){
    if(a<=90&&a>=65)
        return true;
    else if(a>=97&&a<=122)
        return true;
    else
        return false;
}

int main(){
    string key,plainText,encryptedText="";
    int arr[125]={0};
    char matrix[5][5];
    arr['J']=1;
    cout<<"Enter The Key Word : ";
    cin>>key;
    cout<<"Enter The Plain Text To Encrypt : ";
    fflush(stdin);
    getline(cin,plainText);

    int i=0,j=0;

    for(char letter : key){
        if(j==5){
            i++;
            j=0;
        }
        if(isUpperCase(letter)&&arr[letter]!=1){
            arr[letter]=1;
            matrix[i][j]=letter;j++;
        }else if(arr[letter-32]!=1){
            arr[letter-32]=1;
            matrix[i][j]=letter-32;j++;
        }
    }

    for(char k=65;k<=90;k++){
        if(j==5){
            i++;
            j=0;
        }
        if(arr[k]==0){
            arr[k]=1;
            matrix[i][j]=k;
            j++;
        }
    }

    for(int p =0;p<plainText.length();p++){
        char first='$',second='$';

        while((!isAlphabet(plainText[p]))&&p<plainText.length()){
            p++;
        }
        if(p==plainText.length())
            break;
        if(isUpperCase(plainText[p])){
            first= plainText[p];
        }else{
            first= plainText[p]-32;
        }
        int q = p;
        p++;
        while(!isAlphabet(plainText[p])&&p<plainText.length()){
            p++;
        }
        if(p==plainText.length())
            second='X';
        else{
            if(isUpperCase(plainText[p])){
                second= plainText[p];
            }else{
                second= plainText[p]-32;
            }
        }
        if(first==second){
            second='X';
            p= q;
        }
        encryptedText+=first;
        encryptedText+=second;
        encryptedText+=" ";
    }
    int row[125];
    int col[125];

     for(int x =0;x<5;x++){
        for(int y =0;y<5;y++){
            row[matrix[x][y]]=x;
            col[matrix[x][y]]=y;
        }
    }

     for(int x =0;x<5;x++){
        for(int y =0;y<5;y++){
            cout<<matrix[x][y]<<" ";
        }
        cout<<endl;
    }

    for(int p=0;p<encryptedText.length();p++){

        char first= encryptedText[p];
        char second= encryptedText[p+1];

        if(col[first]==col[second]){

            encryptedText[p]=matrix[(row[first]+1)%5][col[first]];
            encryptedText[p+1]=matrix[(row[second]+1)%5][col[second]];

        }else if(row[first]==row[second]){
            encryptedText[p]=matrix[row[first]][(col[first]+1)%5];
            encryptedText[p+1]=matrix[row[second]][(col[second]+1)%5];

        }else{
            encryptedText[p]=matrix[row[first]][col[second]];
            encryptedText[p+1]= matrix[row[second]][col[first]];
        }
        p+=2;
    }

    cout<<encryptedText;

}
