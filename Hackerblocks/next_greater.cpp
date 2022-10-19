#include <bits/stdc++.h>
using namespace std;

/**
 bool isValidChar(char ch) {
     if ( ch >= 'A' && ch <= 'Z' ) {
         return 1 ;
     }
     return 0;
 }

 /**
  * Check if the string have trailing white spaces
  */
bool checkTrailWhitespaces(string str)
{
    if (str[str.size() - 1] == ' ')
    {
        return 1;
    }
    return 0;
}

/**
 * BFS Traversal of a Graph to find out if the graph has Cycle or not and
 * traverse it.
 */
bool bfs(char root, unordered_map<char, unordered_set<char>> &graph, vector<bool> &vis)
{

    deque<pair<char, char>> q;
    bool hasCycle = 0;

    q.push_back({root, ' '});
    vis[root - 'A'] = 1;

    while (!q.empty())
    {
        pair<char, char> ch = q.front();
        q.pop_front();

        for (auto val : graph[ch.first])
        {
            if (!vis[val - 'A'])
            {
                vis[val - 'A'] = 1;
                q.push_back({val, ch.first});
            }
            else if (vis[val - 'A'] && val != ch.second)
            {
                hasCycle = 1;
            }
        }
    }

    return hasCycle;
}

/**
 * Print the S Expression of the graph if the graph is a valid one.
 */
string printSExp(char root, unordered_map<char, unordered_set<char>> &graph, vector<bool> &mark)
{

    if (mark[root - 'A'])
    {
        return "";
    }

    mark[root - 'A'] = 1;
    if (graph[root].size() == 0)
    {
        string ans = "(";
        ans.push_back(root);
        ans += ")";
        return ans;
    }

    string left = "";
    string right = "";
    if (graph[root].size() == 1)
    {
        // Case if only one child is present for a node
        // in a graph
        left = printSExp(*graph[root].begin(), graph, mark);
    }
    else
    {
        // Case if a node has both the children so traverse
        // both to get the result of left and right trees
        char l = *graph[root].begin();
        char r = *(++graph[root].begin());
        if (l < r)
        {
            left = printSExp(*graph[root].begin(), graph, mark);
            right = printSExp(*(++graph[root].begin()), graph, mark);
        }
        else
        {
            left = printSExp(*(++graph[root].begin()), graph, mark);
            right = printSExp(*graph[root].begin(), graph, mark);
        }
    }

    string ans = "(";
    ans.push_back(root);
    ans += left + right + ")";

    return ans;
}
*Check if the Char is in['A' - 'Z'] * /

    int main()
{

    // Get Input
    string str;
    getline(cin, str);

    string buff;
    cin >> buff;

    if (checkTrailWhitespaces(str) && buff.size() > 0)
    {
        cout << "E1" << endl;
        return 0;
    }

    unordered_map<char, unordered_set<char>> graph;
    int error_code = 6;

    // Traversing the whole input and creating a
    // graph in a HashMap form. Also, checking for errors that occur
    // in the input, including error E2, E3.
    for (int i = 0; i < str.size(); i += 6)
    {
        if ((str[i] == '(') &&
            (i + 1 < str.size() && isValidChar(str[i + 1])) &&
            (i + 2 < str.size() && str[i + 2] == ',') &&
            (i + 3 < str.size() && isValidChar(str[i + 3])) &&
            (i + 4 < str.size() && str[i + 4] == ')'))
        {
            // Check for duplicate Pairs - E2
            if (graph[str[i + 1]].find(str[i + 3]) != graph[str[i + 1]].end())
            {
                error_code = min(error_code, 2);
            }
            // Check for E3
            if (graph[str[i + 1]].size() >= 3)
            {
                error_code = min(error_code, 3);
            }
            graph[str[i + 1]].insert(str[i + 3]);
            graph[str[i + 3]].insert(str[i + 1]);
        }
        else
        {
            error_code = 1;
            break;
        }
    }

    // Check if the graph is disconnected or not
    // Check for Cycle too in Graph
    char root = ' ';
    bool hasCycle = 0;
    vector<bool> vis(26, 0);

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (graph.find(ch) != graph.end() && root == ' ')
        {
            root = ch;
            hasCycle = bfs(root, graph, vis);
            break;
        }
    }

    // E3 check for root node
    if (graph[root].size() > 2)
    {
        error_code = min(error_code, 3);
    }

    // Print Errors if any error has occured
    if (error_code != 6)
    {
        cout << "E" << error_code << endl;
        return 0;
    }

    // Check if there is any disconnected trees present
    for (auto val : graph)
    {
        if (!vis[val.first - 'A'])
        {
            cout << "E4" << endl;
            return 0;
        }
    }

    // Check for E5 Error
    if (hasCycle)
    {
        cout << "E5" << endl;
        return 0;
    }

    vector<bool> mark(26, 0);
    // Print the result of the graph
    cout << printSExp(root, graph, mark) << endl;
}
