#include <stdio>
#include <iostream>

/* 功能：
 *   给定一个 string，将其转换为另一个 string
 *   输入两个文件
 *     第一个文件中保存的是一些规则，用来转换第二个文件中的文本
 *       每个规则由两部分组成
 *         一个可能出现在输入文件中的单词和一个用来替换它的短语。每当第一个单词出现在输入中时，就将它替换为对应的短语
 *       第二个文件包含要转换的文本
 */

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if (firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";
            }
            cout << transform(word, trams_map);
        }
        cout << endl;
    }
}

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)
        {
            trans_map[key] = value.substr(1);
        }
        else
        {
            throw runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const string & transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}