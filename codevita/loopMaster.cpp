#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;

// Type Aliases
using ll = long long;
using pii = pair<int, int>;

// Macros
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

// Fast I/O
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

struct Loop
{
    int iterations;
    int current_iteration;
    vector<string> commands;
};

void processCommands(vector<string> &commands, vector<string> &output)
{
    stack<Loop> loopStack;

    for (const auto &command : commands)
    {
        if (command.substr(0, 4) == "for ")
        {
            int times;
            stringstream ss(command.substr(4));
            ss >> times; // Extract the number of times
            loopStack.push({times, 0, {}});
        }
        else if (command == "do")
        {
            // No action needed
        }
        else if (command == "done")
        {
            if (!loopStack.empty())
            {
                Loop topLoop = loopStack.top();
                loopStack.pop();

                // Execute the loop
                for (int i = 1; i <= topLoop.iterations; ++i)
                {
                    for (const auto &cmd : topLoop.commands)
                    {
                        if (cmd.substr(0, 6) == "break ")
                        {
                            int n;
                            stringstream ss(cmd.substr(6));
                            ss >> n;
                            if (i == n)
                            {
                                goto end_loop;
                            }
                        }
                        else if (cmd.substr(0, 9) == "continue ")
                        {
                            int n;
                            stringstream ss(cmd.substr(9));
                            ss >> n;
                            if (i == n)
                            {
                                break; // Skip to the next iteration
                            }
                        }
                        else if (cmd.substr(0, 6) == "print ")
                        {
                            output.push_back(cmd.substr(7, cmd.size() - 8)); // Extract the statement
                        }
                    }
                end_loop:;
                }
            }
        }
        else
        {
            if (!loopStack.empty())
            {
                loopStack.top().commands.push_back(command);
            }
        }
    }
}

int main()
{
    // FAST_IO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<string> cmds(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cmds[i];
    }

    vector<string> output;
    processCommands(cmds, output);

    for (const auto &line : output)
    {
        cout << line << endl;
    }

    return 0;
}
