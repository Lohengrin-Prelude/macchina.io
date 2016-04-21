//
// SwitchServerHelper.cpp
//
// Library: IoT/Devices
// Package: Generated
// Module:  SwitchServerHelper
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2014-2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "IoT/Devices/SwitchServerHelper.h"
#include "IoT/Devices/SwitchEventDispatcher.h"
#include "IoT/Devices/SwitchSkeleton.h"
#include "Poco/RemotingNG/URIUtility.h"
#include "Poco/SingletonHolder.h"


namespace IoT {
namespace Devices {


namespace
{
	static Poco::SingletonHolder<SwitchServerHelper> shSwitchServerHelper;
}


SwitchServerHelper::SwitchServerHelper():
	_pORB(0)
{
	_pORB = &Poco::RemotingNG::ORB::instance();
	_pORB->registerSkeleton("Switch", new SwitchSkeleton);
}


SwitchServerHelper::~SwitchServerHelper()
{
	try
	{
		_pORB->unregisterSkeleton("Switch", true);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


std::string SwitchServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::Devices::SwitchRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return SwitchServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}


Poco::AutoPtr<IoT::Devices::SwitchRemoteObject> SwitchServerHelper::createRemoteObjectImpl(Poco::SharedPtr<IoT::Devices::Switch> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return new SwitchRemoteObject(oid, pServiceObject);
}


void SwitchServerHelper::enableEventsImpl(const std::string& uri, const std::string& protocol)
{
	Poco::RemotingNG::Identifiable::Ptr pIdentifiable = _pORB->findObject(uri);
	Poco::AutoPtr<SwitchRemoteObject> pRemoteObject = pIdentifiable.cast<SwitchRemoteObject>();
	if (pRemoteObject)
	{
		pRemoteObject->remoting__enableRemoteEvents(protocol);
	}
	else throw Poco::NotFoundException("remote object", uri);
}


SwitchServerHelper& SwitchServerHelper::instance()
{
	return *shSwitchServerHelper.get();
}


std::string SwitchServerHelper::registerObjectImpl(Poco::AutoPtr<IoT::Devices::SwitchRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return _pORB->registerObject(pRemoteObject, listenerId);
}


void SwitchServerHelper::unregisterObjectImpl(const std::string& uri)
{
	_pORB->unregisterObject(uri);
}


} // namespace Devices
} // namespace IoT

