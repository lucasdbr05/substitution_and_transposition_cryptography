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

        string get_rails_text() {
            string chipher_text = "";

            for(int i=0; i< this->k; i++){
                for(auto c: this->rails[i]) {
                    if(c != '*') {
                        chipher_text += c;
                    }
                }
            }
            return chipher_text;
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

            return get_rails_text();
        }

        string decrypt(string chipher_text) {
            int n = chipher_text.size();

            rails = vector(k, vector<char>(n, '*'));
            
            int diff = 2 * (k-1) -1;
            for(int i=0; i<k; i++) {
                for(int j=i; j<n; j+= diff) {
                    rails[i][j] = chipher_text[j];
                    if(i*2-1 > 0) {
                        j+= 2*i+1;
                        rails[i][j] = chipher_text[j];
                    }
                }
                diff  = (diff-2<0 ? 0: diff - 2);
            }
            return get_rails_text(); 
        }
};