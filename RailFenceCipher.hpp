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
                return -1; // to go up
            } 
            if(rail + direction < 0) {
                return 1; // to go down
            }
            return direction;// to keep the direction
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
            int direction = 1; // 1 -> down | -1 -> down

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


            int diff = 2*(k-1) ;
            int curr = 0;
            for(int i=0; i<k; i++){
                for(int j = i; j<n; j+= diff) {
                    rails[i][j] = cipher_text[curr];
                    curr+= (diff != 0);
                    if(2*i-1>0) {
                        j+= 2*i;
                        if(j>=n) continue;
                        rails[i][j] = cipher_text[curr];
                        curr++;
                    }
                }
                diff = (diff-2<0 ? 0 : diff-2);
            }
            
            return get_rails_text(false); 
        }
};