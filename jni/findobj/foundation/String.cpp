#include "String.h"
#include "Constant.h"
#include "findobj/Util.h"

String::String()
{
	mData = NULL;
	mLength = 0;
}

String::String(const char *data)
{
	mData = NULL;
	mLength = 0;
	if(data != NULL) {
		mLength = strlen(data);
		if(mLength > 0) {
			mData = new char[mLength];
			memcpy(mData, data, mLength);
		}
	}
}

String::~String()
{
	if(mData != NULL) {
		delete mData;
	}
}

int String::length()
{
	return mLength;
}

char String::charAt(int index)
{
	return mData[index];
}

char* String::toCharArray()
{
	char *data = new char[mLength + 1];
	if(mLength > 0) {
		memcpy(data, mData, mLength);
	}
	data[mLength] = '\0';
	return data;
}

bool String::equals(Object *obj)
{
	if(obj != NULL &&
			obj->instanceOf(this->whoAmI())) {
		String *str = (String*)obj;
		if(mData != NULL &&
				str->mData != NULL &&
				mLength == str->mLength) {
			return (0 == memcmp(mData, str->mData, mLength));
		}
	}
	return false;
}

int String::hashCode()
{
	if(mData == NULL ||
			mLength <= 0) {
		return Object::hashCode();
	}

	unsigned long h = 0, g;
	int len = mLength;
	char *keyStart = mData;
	char *keyEnd = keyStart + len;

	while (keyStart < keyEnd) {
		h = (h << 4) + *keyStart++;
		if ((g = (h & 0xF0000000))) {
			h = h ^ (g >> 24);
			h = h ^ g;
		}
	}

	return h;
}

const char* String::whoAmI()
{
	return "findobj.foundation.String";
}
