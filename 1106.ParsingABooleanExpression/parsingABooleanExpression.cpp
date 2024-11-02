
# include <iostream>
# include <string>

using namespace std;


class Solution {
public:
    bool parseBoolExpr(string expression) {
        int ad = 1, o = 0, note = 0, operation = 0;
        std::stack<char> stk;

        for ( int i = 0; i < expression.size(); i++ ) {
            ad = 1, o = 0;
            if ( !stk.empty() && expression[i] == ')' ) {
                char c;
                while( !stk.empty() && ( stk.top() == 't' || stk.top() == 'f' ) ) {

                    c = stk.top();
                    stk.pop();
                    
                    if ( c == 'f' ) {
                        ad &= 0;
                        o |= 0;
                        note = 1;
                    }
                    else {
                        ad &= 1;
                        o |= 1;
                        note = 0;
                    }
                }

                c = stk.top();
                stk.pop();

                if ( c == '&' ) {
                    stk.push(ad == 1 ? 't' : 'f');
                }
                else if ( c == '|' ) {
                    stk.push( o == 1 ? 't' : 'f' );
                    operation = 0;
                }
                else {
                    stk.push( note == 1 ? 't' : 'f' );
                }

            }
            else if ( expression[i] != ',' && expression[i] != '(') {
                stk.push( expression[i] );
            }

        }
        return stk.top() == 'f' ? 0 : 1;
    }
};