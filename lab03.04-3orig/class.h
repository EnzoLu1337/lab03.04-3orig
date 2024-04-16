#pragma once
#include <numeric> 
#include <vector>
#include <algorithm>
#include <string>

class Athlete {
private:
	std::string name;
	int number;
	std::vector<int> results;
public:
	Athlete(const std::string& name, int number, const std::vector<int>& results): 
		name(name), 
		number(number), 
		results(results) 
	{}

	int getTotalResult() const {
		return std::accumulate(results.begin(), results.end(), 0);
	}

	const std::string& getName() const {
		return name;
	}

	int getNumber() const {
		return number;
	}

	const std::vector<int>& getResults() const {
		return results;
	}

	bool operator<(const Athlete& other) const {
		return getTotalResult() < other.getTotalResult();
	}
};