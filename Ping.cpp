#include "Ping.h"

#define	DEFDATALEN (64-ICMP_MINLEN)
#define	MAXIPLEN 60
#define	MAXICMPLEN 76



uint16_t in_cksum(uint16_t *addr, unsigned len)
{
  uint16_t answer = 0;
  /*
   * Algorithm is simple, using a 32 bit accumulator (sum), add
   * sequential 16 bit words to it, and at the end, fold back all the
   * carry bits from the t   16 bits into the lower 16 bits.
   */
  uint32_t sum = 0;
  while (len > 1)  {
    sum += *addr++;
    len -= 2;
  }

  if (len == 1) {
    *(unsigned char *)&answer = *(unsigned char *)addr ;
    sum += answer;
  }

  sum = (sum >> 16) + (sum & 0xffff);
  sum += (sum >> 16);
  answer = ~sum;
  return answer;
}

Ping::Ping() {
}

Ping::Ping(std::string ip) {
    this->ip = ip;
    this->initSendToSockAddr();
}

void Ping::initSendToSockAddr() {
    this->sendTo.sin_family = SOCK_DOMAIN;
    this->sendTo.sin_addr.s_addr = inet_addr(this->ip.c_str());
}

Ping::Ping(const Ping& orig) {
}

void Ping::startPinging() {
    int ssize;
    unsigned char buff[MAX_ICMP_DATA_SIZE];
    
    int cc = DEFDATALEN + ICMP_MINLEN;
    struct icmp *icp;
    icp = (struct icmp *)buff;
    icp->icmp_type = ICMP_ECHO;
    icp->icmp_code = 0;
    icp->icmp_cksum = 0;
    icp->icmp_seq = 12345;
    icp->icmp_id = getpid();
    icp->icmp_cksum = in_cksum((unsigned short *)icp, cc);
    
    ssize = sendto(this->sockFd, (unsigned char*)buff, cc, 0, (struct sockaddr*)&this->sendTo, (socklen_t)sizeof(struct sockaddr_in));
    
    /*int ssize, cc, retval, fromlen, ret, packlen, hlen, end_t;
    cc = DEFDATALEN + ICMP_MINLEN;
    u_char *packet, outpack[MAX_ICMP_DATA];
    struct ip *ip;
    fd_set rfds;
    struct timeval tv;
    struct timeval start, end;
    
     * /
   
    //ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
    //           const struct sockaddr *dest_addr, socklen_t addrlen);
    
    
    struct sockaddr_in from;
    
    packlen = DEFDATALEN + MAXIPLEN + MAXICMPLEN;
    /*if ( (packet = (u_char *)malloc((u_int)packlen)) == NULL)
	{
		cerr << "malloc error\n";
		//return -1;
	}
     */
    
    //ssize = sendto(this->sockFd, (char *)outpack, cc, 0, (struct sockaddr*)&this->sendTo, (socklen_t)sizeof(struct sockaddr_in));
    /*if (ssize < 0 || ssize != cc)
	{
		if (ssize < 0)
			perror("sendto error");
		cout << "wrote " <<  "hoestname " <<  cc << " chars, ret= " << ssize << endl;
	}
     */
    
   /*
    FD_ZERO(&rfds);
	FD_SET(this->sockFd, &rfds);
	tv.tv_sec = 1;
	tv.tv_usec = 0;
        bool cont = true;
     */
        /*
    while(cont)
	{
		retval = select(s+1, &rfds, NULL, NULL, &tv);
		if (retval == -1)
		{
			perror("select()");
			//return -1;
		}
		else if (retval)
		{
			fromlen = sizeof(sockaddr_in);
			if ( (ret = recvfrom(s, (char *)packet, packlen, 0,(struct sockaddr *)&from, (socklen_t*)&fromlen)) < 0)
			{
				perror("recvfrom error");
				//return -1;
			}

			// Check the IP header
			ip = (struct ip *)((char*)packet); 
			hlen = sizeof( struct ip ); 
			if (ret < (hlen + ICMP_MINLEN)) 
			{ 
				cerr << "packet too short (" << ret  << " bytes) from " << this->ip << endl;;
				//return -1; 
			} 

			// Now the ICMP part 
			icp = (struct icmp *)(packet + hlen); 
			if (icp->icmp_type == ICMP_ECHOREPLY)
			{
				if (icp->icmp_seq != 12345)
				{
					cout << "received sequence # " << icp->icmp_seq << endl;
					continue;
				}
				if (icp->icmp_id != getpid())
				{
					cout << "received id " << icp->icmp_id << endl;
					continue;
				}
				cont = false;
			}
			else
			{
				cout << "Recv: not an echo reply" << endl;
				continue;
			}
	
			gettimeofday(&end, NULL);
			end_t = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

			if(end_t < 1)
				end_t = 1;

			cout << "Elapsed time = " << end_t << " usec" << endl;
			return end_t;
		}
		else
		{
			cout << "No data within one seconds.\n";
			//return 0;
		}
	}
         */
}


Ping::~Ping() {
}

