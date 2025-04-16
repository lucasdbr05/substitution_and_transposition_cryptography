#pragma once
#include <string>
#include <vector>
using namespace std;

class RailFenceCipher {
    private:
        int k;
        vector<vector<char>> rails;

        int update_direction(int rail, int direction) {
            if (rail + direction == k) {
                direction =  -1; // change to go up
            } 
            if(rail + direction < 0) {
                direction =  1; // change go down
            }
            return direction; // keep the direction
        }

        string get_rails_text(bool encrypt) {
            string text = "";

            if(encrypt) {
                for(int i=0; i< k; i++){
                    for(auto c: rails[i]) {
                        if(c != '*') {
                            text += c;
                        }
                    }
                }
            } else {
                int direction = 1, rail = 0;
                int n = rails[0].size();
                for(int i=0; i<n; i++){
                    text += rails[rail][i];
                    direction = update_direction(rail, direction);
                    rail += direction;
                }
            }
            return text;
        }

    public:
        RailFenceCipher(){}
        
        RailFenceCipher(int n_rails) {
            this->k = n_rails;
        }

        string encrypt(string message) {
            int n = message.size();
            rails = vector(k, vector<char>(n, '*'));

            int rail = 0;
            int direction = 1;

            for(int i=0; i<n; i++){
                rails[rail][i] = message[i];
                direction = update_direction(rail, direction);
                rail += direction;
            }

            return get_rails_text(true);
        }

        string decrypt(string cipher_text) {
            int n = cipher_text.size();

            rails = vector(k, vector<char>(n, '*'));
            vector<int> rails_len = vector<int>(k, 0);
            
            int direction = 1, rail = 0;
            for(int i=0; i<n; i++){
                rails_len[rail]++;
                direction = update_direction(rail, direction);
                rail += direction;
            }


            int diff = 2*(k-1), i = 0;
            for(int rail=0; rail<k; rail++) {
                for(int j = rail; j<n;) {
                    rails[rail][j] = cipher_text[i];
                    j+= diff; i+= (diff != 0); 
                    if(2*rail-1>0) {
                        if(j>=n) continue;
                        rails[rail][j] = cipher_text[i];
                        j+= 2*rail;i++;
                    }
                }
                diff = (diff-2<0 ? 0 : diff-2);
            }

            for(int i=0; i<k; i++) {
                for(int j=0; j<n; j++) {
                    cout << rails[i][j];
                }
                cout << "\n";
            }
            cout << "\n";

            return get_rails_text(false); 
        }
};