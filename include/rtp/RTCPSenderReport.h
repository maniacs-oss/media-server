/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RTCPSenderReport.h
 * Author: Sergio
 *
 * Created on 3 de febrero de 2017, 11:59
 */

#ifndef RTCPSENDERREPORT_H
#define RTCPSENDERREPORT_H

class RTCPSenderReport : public RTCPPacket
{
public:
	RTCPSenderReport();
	virtual ~RTCPSenderReport();
	virtual void Dump();
	virtual DWORD GetSize();
	virtual DWORD Parse(BYTE* data,DWORD size);
	virtual DWORD Serialize(BYTE* data,DWORD size);

	void SetOctectsSent(DWORD octectsSent)	{ this->octectsSent = octectsSent;	}
	void SetPacketsSent(DWORD packetsSent)	{ this->packetsSent = packetsSent;	}
	void SetRtpTimestamp(DWORD rtpTimestamp){ this->rtpTimestamp = rtpTimestamp;	}
	void SetSSRC(DWORD ssrc)		{ this->ssrc = ssrc;			}
	void SetNTPFrac(DWORD ntpFrac)		{ this->ntpFrac = ntpFrac;		}
	void SetNTPSec(DWORD ntpSec)		{ this->ntpSec = ntpSec;		}

	DWORD GetOctectsSent()	const		{ return octectsSent;		}
	DWORD GetPacketsSent()	const		{ return packetsSent;		}
	DWORD GetRTPTimestamp() const		{ return rtpTimestamp;		}
	DWORD GetNTPFrac()	const		{ return ntpFrac;		}
	DWORD GetNTPSec()	const		{ return ntpSec;		}
	QWORD GetNTPTimestamp()	const		{ return ((QWORD)ntpSec)<<32 | ntpFrac ;	}
	DWORD GetSSRC()		const		{ return ssrc;			}

	DWORD GetCount()	const		{ return reports.size();	}
	RTCPReport* GetReport(BYTE i) const	{ return reports[i];		}
	void  AddReport(RTCPReport* report)	{ reports.push_back(report);	}

	void  SetTimestamp(timeval *tv);
	QWORD GetTimestamp() const;
	void  GetTimestamp(timeval *tv) const;

private:
	DWORD ssrc;           /* sender generating this report */
	DWORD ntpSec;	      /* NTP timestamp */
	DWORD ntpFrac;
	DWORD rtpTimestamp;   /* RTP timestamp */
	DWORD packetsSent;    /* packets sent */
	DWORD octectsSent;    /* octets sent */

private:
	Reports	reports;
};


#endif /* RTCPSENDERREPORT_H */

