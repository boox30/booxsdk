#include "onyx/sys/sys_status.h"
#include "onyx/sys/wpa_connection_manager.h"


WpaConnectionManager::WpaConnectionManager()
: proxy_(sys::SysStatus::instance().wpa_proxy())
, count_(0)
, internal_state_(WpaConnection::STATE_UNKNOWN)
, auto_connect_(true)
, wifi_enabled_(true)
{
    setupConnections();
    scan_timer_.setInterval(1500);
}

WpaConnectionManager::~WpaConnectionManager()
{
}

// Reset state machine and start the following actions
// - scan
// - connect to certain if ap is connected before
// - automatically fill password if necessary
// - broadcast signals when state changed
void WpaConnectionManager::start()
{
}

void WpaConnectionManager::stop()
{
}

void WpaConnectionManager::onSdioChanged(bool on)
{
}

void WpaConnectionManager::onScanTimeout()
{
}

void WpaConnectionManager::onScanReturned(WifiProfiles & list)
{
}

void WpaConnectionManager::scanResults(WifiProfiles &)
{
}

void WpaConnectionManager::onNeedPassword(WifiProfile profile)
{
}

void WpaConnectionManager::onConnectionChanged(WifiProfile &,
                                               WpaConnection::ConnectionState state)
{
}

void WpaConnectionManager::onConnectionTimeout()
{
}

void WpaConnectionManager::onComplete()
{
}

bool WpaConnectionManager::checkWpaSupplicant()
{
    return true;
}

void WpaConnectionManager::setupConnections()
{
    QObject::connect(&scan_timer_, SIGNAL(timeout()), this, SLOT(onScanTimeout()));

    SysStatus & sys = sys::SysStatus::instance();
    QObject::connect(&sys, SIGNAL(sdioChangedSignal(bool)), this, SLOT(onSdioChanged(bool)));

    QObject::connect(&proxy_, SIGNAL(scanResultsReady(WifiProfiles &)),
            this, SLOT(onScanReturned(WifiProfiles &)));
    QObject::connect(&proxy_, SIGNAL(stateChanged(WifiProfile &,WpaConnection::ConnectionState)),
        this, SLOT(onConnectionChanged(WifiProfile &, WpaConnection::ConnectionState)));
    QObject::connect(&proxy_, SIGNAL(needPassword(WifiProfile )),
            this, SLOT(onNeedPassword(WifiProfile )));

}

void WpaConnectionManager::resetProfile(WifiProfile & profile)
{
}

void WpaConnectionManager::setPassword(WifiProfile & profile, const QString & password)
{
}

bool WpaConnectionManager::checkAuthentication(WifiProfile & profile)
{
    return true;
}

bool WpaConnectionManager::syncAuthentication(WifiProfile & source,
                                              WifiProfile & target)
{
    return true;
}

void WpaConnectionManager::saveAp(WifiProfile & profile)
{
}

bool WpaConnectionManager::isConnecting()
{
    return true;
}

void WpaConnectionManager::setConnecting(bool c)
{
}

void WpaConnectionManager::stopAllTimers()
{
}

WifiProfiles & WpaConnectionManager::records(sys::SystemConfig& conf)
{
    return scan_results_;
}
