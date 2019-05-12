#ifndef MY_TRIM
#define MY_TRIM
#include <string>
#include <vector>
#include <algorithm>
static void delete_spaces(std::string& s)
{
    std::string tmp = "";
	const std::size_t length = s.length();
	for (std::size_t ix = 0; ix < length; ++ix)
	{
		if (s[ix] == ' ' && s[ix + 1] == ' ')
		{
			continue;
		}
		tmp += s[ix];
	}
	s = tmp;
}
static void delete_tab_n_other(std::string& s)
{
	std::string tmp = "";
	const std::size_t length = s.length();
	for (std::size_t ix = 0; ix < length; ++ix)
	{
        if (s[ix] == '\t' || s[ix] == '\r' || s[ix] == '|')
		{
			continue;
		}
		tmp += s[ix];
	}
	s = tmp;
}

static void delete_substr(std::string & s, std::string & substr)
{
	std::string tmp;
	if (s.find(substr) != std::string::npos)
	{
		std::size_t pos = s.find(substr);
		tmp = s.substr(0, pos);
		s = tmp + s.substr(pos + substr.length(), s.length());
	}
}

static void delete_html(std::string& s)
{
	std::vector < std::string > html_tags;

	html_tags.push_back("< / p>");
	html_tags.push_back("< strong>");
	html_tags.push_back("< / strong>");
	html_tags.push_back("< / a>");
	html_tags.push_back("< / h3>");
	html_tags.push_back("< / i>");
	html_tags.push_back("< / span>");
	html_tags.push_back("< / span >");
	html_tags.push_back("< / small>");
	html_tags.push_back("< / div>");
	html_tags.push_back("< / td>");
	html_tags.push_back("< / tr>");
    html_tags.push_back("<li>");
    html_tags.push_back("<br />");
    html_tags.push_back(" <br />");


	for (auto str : html_tags)
		delete_substr(s, str);

}
//"< / i>Львов, Галицкий                                    < / span>\t\t< / small>\t\t"
//"< / i>Сегодня 13:19 < / span >\t\t< / small>\t\t< / p>\t\t< / div>\t\t< / td>\t\t"
//"Продам 3 кімн кв на Лукаша< / strong>\t\t< / a>\t\t< / h3>\t\t"
//"\t\t< strong>1 656 960 грн.< / strong>\t\t< / p>\t\t< / div>\t\t< / td>\t\t< / tr>\t\t"
static void my_trim(std::string& s)
{
	delete_tab_n_other(s);
	delete_html(s);

	delete_spaces(s);

    std::string::size_type pos = 0;
    while ((pos = s.find("&quot;", pos)) != std::string::npos)
    {
        s.replace(pos, 6, "\"");
        pos += 2;
    }
}
#endif
