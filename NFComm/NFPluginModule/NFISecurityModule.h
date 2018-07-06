/*
            This file is part of: 
                NoahFrame
            http://noahframe.com

   Copyright 2009 - 2018 NoahFrame(NoahGameFrame)

   File creator: lvsheng.huang
   
   NoahFrame is opensorece software and you can redistribute it and/or modify
   it under the terms of the License.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/



#ifndef NFI_SECURITY_MODULE_H
#define NFI_SECURITY_MODULE_H

#include "NFIModule.h"

class NFISecurityModule : public NFIModule
{
public:
	//when a user login NF system, as a security module, you need to grant user an key.
	virtual const std::string& GetSecurityKey(const std::string& strAcount) = 0;

	//when the user want to connect to proxy, as a user need to provide the key that got in login system.
	virtual bool VirifySecurityKey(const std::string& strAcount, const std::string& strSucrityKey) = 0;

	//when the user want to post a message to proxy, the message-data need to be virified.
	virtual std::string EncodeMsg(const std::string& strAcount, const std::string& strSucrityKey, const int nMessageID, const char* strMessageData, const int nLen) = 0;
	virtual std::string EncodeMsg(const std::string& strAcount, const std::string& strSucrityKey, const int nMessageID, const std::string& strMessageData) = 0;
	virtual std::string DecodeMsg(const std::string& strAcount, const std::string& strSucrityKey, const int nMessageID, const char* strMessageData, const int nLen) = 0;
	virtual std::string DecodeMsg(const std::string& strAcount, const std::string& strSucrityKey, const int nMessageID, const std::string& strMessageData) = 0;

};

#endif