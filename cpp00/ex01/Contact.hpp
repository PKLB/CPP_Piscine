#ifndef CONTACT_HPP
# define CONTACT_HPP
using std::string;

class Contact {
	private :
		string	_FirstName;
		string	_LastName;
		string	_Nickname;
		string	_PhoneNumber;
		string	_DarkestSecret;
	public:
		string getFirstName();
		string getLastName();
		string getNickname();
		string getDarkestSecret(); 
		string getPhoneNumber(); 
		void	modifyFirstName(const string str);
		void	modifyLastName(const string str);
		void	modifyNickname(const string str);
		void	modifyDarkestSecret(const string str);
		void	modifyPhoneNumber(const string str);
};

#endif