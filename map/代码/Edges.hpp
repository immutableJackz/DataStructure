#include"headAll.h"
#pragma once
class Edges
{
private:
	int from;//起始点 编号
	int to;//终点 编号
	double wt; //权重
public:
	Edges() {};
	Edges(int from ,int to,int wt)
		:from(from),to(to),wt(wt){}
	int getTo() { return to; }
	int getFrom() { return from; }
	int getWt() { return wt; }
	void setTo(int to) { this->to = to; }
	void setFrom(int from) {  this->from=from; }
	void setWt(double wt) { this->wt = wt; }
};

