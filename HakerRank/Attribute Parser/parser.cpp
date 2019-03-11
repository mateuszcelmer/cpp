#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
using namespace std;

class Html
{
  public:
    map<string, Html *> children;
    string tag = "_new_";
    map<string, string> params;

  public:
    void init(vector<stringstream> &v)
    {
        bool child_ready = false;
        while (v.size() > 0)
        {
            auto &i = v[0];
            string str;
            bool czytaj_dalej = true;
            string key, value;
            char ch;
            stringstream cpy(i.str().c_str());
            cpy >> ch;
            //cout << "ch = " << ch << endl;
            if (ch != '<')
                break;
            if (child_ready)
            {
                stringstream cpy(i.str().c_str());
                cpy >> str;
                if (str == "<" + tag + ">" || str == "<" + tag)
                {
                    v.erase(v.begin());
                    cpy = stringstream(i.str().c_str());
                    cpy >> str;
                }
                if (str[1] == '/')
                {
                    v.erase(v.begin());
                    return; // jesli / zamykajacy wyjdz
                }
                else // w przeciw. nowy tag child - utworz
                {
                    Html *child = new Html(v);
                    children.insert(make_pair(child->tag, child));
                }
            }
            if (!child_ready)
            // wczytaj params tego obiektu
            {
                i >> ch; // pobierz <
                i >> tag;
                // jesli ostatnia ch != '>' to załaduj key i value
                if (tag.back() != '>')
                    while (czytaj_dalej) // wczytaj wszystkie params
                    {
                        i >> key >> ch >> value;
                        if (value.back() == '>')
                        {
                            czytaj_dalej = false;
                            value.pop_back();
                        }
                        // usun " " z value
                        value = value.substr(1, value.size() - 2);
                        params.insert(make_pair(key, value));
                    }
                else
                    tag.pop_back(); // jesli na koncu > to usun
                child_ready = true;
                //cout << "tag = " <<tag << endl;
            }
        }
    }
    Html(vector<stringstream> &v) { init(v); }
};

string read_key(string &str, char &ch)
{
    string key = "";
    while (str.size() > 0)
    {
        if (str[0] == '.')
        {
            ch = '.';
            str.erase(str.begin()); // pop front
            return key;
        }
        if (str[0] == '~')
        {
            ch = '~';
            str.erase(str.begin()); // pop front
            return key;
        }
        key += str[0];
        str.erase(str.begin()); // pop front
    }
    return key;
};

string read_key(string &str)
{
    string key = "";
    while (str.size() > 0)
    {
        key += str[0];
        str.erase(str.begin()); // pop front
    }
    return key;
};

void print_line(Html &elem, string str)
{
    char ch;
    string key = read_key(str, ch);

    // sprawdz czy key znajduje się wsrod children
    auto it = elem.children.find(key);
    if (it == elem.children.end())
    {
        cout << "Not Found!" << endl;
        return;
    }

    //cout << "key: " << key << endl;
    if (ch == '.')
        print_line(*elem.children[key], str);
    if (ch == '~')
    {
        string new_key = read_key(str);
        //cout << "new key: " << new_key << endl;
        auto it = elem.children[key]->params.find(new_key);
        if (it != elem.children[key]->params.end())
            cout << it->second << endl;
        else
            cout << "Not Found!" << endl;
    }
}

void print(Html &elem, vector<string> queries)
{
    for (auto &q : queries)
    {
        print_line(elem, q);
    }
};

void print_all(Html &elem, string prefix = "")
{
    cout << prefix << elem.tag;
    for (auto &&i : elem.params)
        cout << "[k: " << i.first << ", v:" << i.second << "] ";
    cout << endl;
    if (elem.children.size() > 0)
        for (auto &&i : elem.children)
            print_all(*i.second, "-" + prefix);
}

int main()
{
    stringstream input("10 10\n<a value = \"GoodVal\">\n<b value = \"BadVal\" size = \"10\">\n</b>\n<c height = \"auto\">\n<d size = \"3\">\n<e strength = \"2\">\n</e>\n</d>\n</c>\n</a>\na~value\nb~value\na.b~size\na.b~value\na.b.c~height\na.c~height\na.d.e~strength\na.c.d.e~strength\nd~sze\na.c.d~size");

    int n, q;
    input >> n >> q;

    char str[200];
    input.getline(str, 200);

    // wcyztaj html
    vector<stringstream> v;
    v.push_back(stringstream("<parent>"));
    while (n--)
    {
        input.getline(str, 200);
        v.push_back(stringstream(str));
    }
    v.push_back(stringstream("</parent>"));

    //wczytaj queries
    vector<string> queries;
    while (q--)
    {
        input.getline(str, 200);
        queries.push_back(str);
    }

    Html elem(v);

    print_all(elem);
    print(elem, queries);

    return 0;
}