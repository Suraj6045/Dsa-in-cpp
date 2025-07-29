#include<iostream>
using namespace std;

void normal_pattern(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

void half_pyramid(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

void number_half_pyramid_type1(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            cout << j;
        }
        cout << "\n";
    }
}

void number_half_pyramid_type2(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            cout << i;
        }
        cout << "\n";
    }
}

void inverted_half_pyramid(int n){
    for(int i = n ; i>=1 ; i--){
        for(int j=1 ; j<=i ; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

void number_inverted_half_pyramid(int n){
    for(int i = n ; i>=1 ; i--){
        for(int j=1 ; j<=i ; j++){
            cout << j;
        }
        cout << "\n";
    }
}

void pyramid(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=n-i ; j++){
            cout << " ";
        }

        for(int j=1 ; j<=2*i-1 ; j++){
            cout << "*";
        }

        cout << "\n";
    }
}

void inverted_pyramid(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i-1 ; j++){
            cout << " ";
        }

        for(int j=1 ; j<=2*(n-i)+1 ; j++){
            cout << "*";
        }

        cout << "\n";
    }
}

void diamond(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=n-i ; j++){
            cout << " ";
        }

        for(int j=1 ; j<=2*i-1 ; j++){
            cout << "*";
        }

        cout << "\n";
    }

    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i-1 ; j++){
            cout << " ";
        }

        for(int j=1 ; j<=2*(n-i)+1 ; j++){
            cout << "*";
        }

        cout << "\n";
    }
}

void half_diamond(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            cout << "*";
        }

        cout << "\n";
    }

    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=n-i ; j++){
            cout << "*";
        }

        cout << "\n";
    }
}

void number_triangle_pattern1(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            if((i+j)%2==0){
                cout << 1;
            }
            else {
                cout << 0;
            }
        }

        cout << "\n";
    }
}

void number_triangle_pattern2(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            cout << j;
        }

        for(int j=1 ; j<=2*(n-i) ; j++){
            cout << " ";
        }

        for(int j=i ; j>=1 ; j--){
            cout << j;
        }

        cout << "\n";
    }
}

void number_triangle_pattern3(int n){
    int num = 1;
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
           cout << num << " ";
           num ++;
        }

        cout << "\n";
    }
}

void character_triangle_pattern1(int n){
    for(int i = 1 ; i<=n ; i++){
        char charac = 'A';
        for(int j=1 ; j<=i ; j++){
           cout << charac;
           charac ++;
        }

        cout << "\n";
    }
}

void character_triangle_pattern2(int n){
    for(int i = 1 ; i<=n ; i++){
        char charac = 'A';
        for(int j=1 ; j<=n-i+1 ; j++){
           cout << charac;
           charac ++;
        }

        cout << "\n";
    }
}

void character_triangle_pattern3(int n){
    char charac = 'A';
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
           cout << charac;
        }
        charac ++;
        cout << "\n";
    }
}

void character_triangle_pattern4(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j=1 ; j<=n-i ; j++){
           cout << " ";
        }

        char charac = 'A';
        for(int j=1 ; j<=i ; j++){
           cout << charac;
           charac ++;
        }

        charac --;
        for(int j=1 ; j<=i-1 ; j++){
            charac --;
           cout << charac;
        }

        cout << "\n";
    }
}

void character_triangle_pattern5(int n){
    for(int i = 1 ; i<=n ; i++){
        char charac = 'A';
        charac += n-i;
        for(int j=1 ; j<=i ; j++){
            cout << charac;
            charac ++;
        }

        cout << "\n";
    }
}

void hollow_diamond(int n){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n-i+1 ; j++){
            cout << "*";
        }
        for(int j=1 ; j<=2*(i-1) ; j++){
            cout << " ";
        }
        for(int j=1 ; j<=n-i+1 ; j++){
            cout << "*";
        }
        cout << "\n";
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            cout << "*";
        }
        for(int j=1 ; j<=2*(n-i) ; j++){
            cout << " ";
        }
        for(int j=1 ; j<=i ; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

void butterfly(int n){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            cout << "*";
        }
        for(int j=1 ; j<=2*(n-i) ; j++){
            cout << " ";
        }
        for(int j=1 ; j<=i ; j++){
            cout << "*";
        }
        cout << "\n";
    }

    for(int i=1 ; i<=n-1 ; i++){
        for(int j=1 ; j<=n-i ; j++){
            cout << "*";
        }
        for(int j=1 ; j<=2*(i) ; j++){
            cout << " ";
        }
        for(int j=1 ; j<=n-i ; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

void square(int n){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i==1 || j==1 || j==n || i==n){
                cout << "*" << " ";
            }
            else{
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

void spiral_pattern(int n){
    for(int i=0 ; i<2*n-1 ; i++){
        for(int j=0 ; j<2*n-1 ; j++){
            int top = i;
            int bottom = 2*n-2-i;
            int left = j;
            int right = 2*n-2-j;
            cout << n-min(min(top,bottom),min(right,left));
        }
        cout << "\n";
    }
}

int main(){
    spiral_pattern(4);
    
}