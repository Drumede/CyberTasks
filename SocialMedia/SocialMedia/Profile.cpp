#include "Profile.h"

void Profile::init(User owner) {
	this->owner = owner;
	this->page = new Page;
	this->page->init();
	this->friends = new UserList;
	this->friends->init();
}

void Profile::clear() {
	this->page->clearPage();
	this->friends->clear();
}

User Profile::getOwner() const {
	return this->owner;
}

void Profile::setStatus(std::string new_status) {
	this->page->setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post) {
	this->page->addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add) {
	this->friends->add(friend_to_add);
}

std::string Profile::getPage() const {
	return "Status: " + this->page->getStatus() + "\n*******************\n*******************\n" + this->page->getPosts();
}

std::string Profile::getFriends() const {
	UserNode* temp;
	std::string returnval = "";
	temp = this->friends->get_first();
	if (temp == nullptr)
		return "";
	while (temp != nullptr)
	{
		returnval += temp->get_data().getUserName() + ",";
		temp = temp->get_next();
	}
	if (returnval.empty())
		return returnval;
	returnval.pop_back();
	return returnval;
}

std::string Profile::getFriendsWithSameNameLength() const {
	UserNode* temp;
	std::string returnval = "";
	temp = this->friends->get_first();
	if (temp == nullptr)
		return "";
	while (temp != nullptr)
	{
		if (temp->get_data().getUserName().length() == this->owner.getUserName().length())
			returnval += temp->get_data().getUserName() + ",";
		temp = temp->get_next();
	}
	if (returnval.empty())
		return returnval;
	returnval.pop_back();
	return returnval;
}

void Profile::changeAllWordsInStatus(std::string word) {
	std::string result;
	bool inWord = false;

	for (size_t i = 0; i < this->page->getStatus().size(); ++i) {
		char c = this->page->getStatus()[i];
		bool isSpace = (c == ' ' || c == '\t' || c == '\n');

		if (isSpace) {
			result += c;      // keep spacing exactly the same
			inWord = false;
		}
		else {
			if (!inWord) {
				result += word;
				inWord = true;
			}
			// skip over word chars without copying them
		}
	}

	this->page->setStatus(result);
}

void Profile::changeWordInStatus(std::string word_to_replace, std::string new_word) {
	std::string result = this->page->getStatus();
	size_t pos = 0;

	while ((pos = result.find(word_to_replace, pos)) != std::string::npos) {
		// check word boundaries

		result.replace(pos, word_to_replace.size(), new_word);
		pos += new_word.size();
	}

	this->page->setStatus(result);
}