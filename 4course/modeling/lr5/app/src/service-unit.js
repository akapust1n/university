include('src/random.js');

function Store(time) {
	let self = this;
	
	self.time = time;

	let orders = [];

	self.pushOrder = function(nowTime) {
		orders.push(nowTime);
	}

	self.run = function(nowTime) {
		//orders.sort((a, b) => a - b);

		let i = 0;
		while(orders[i] + self.time < nowTime) {
			orders.shift();
			++i;
		}

		return i;
	}
}

function ServiceUnit(min, max, store) {
	let self = this;
	
	self.min = min;
	self.max = max;
	self.store = store;

	let isFree = false;
	
	let timeNewWork = randFromMinToMax(self.min, self.max);

	self.isFree = function(nowTime) {
		if (nowTime >= timeNewWork && !isFree) {
			isFree = true;
			self.store.pushOrder(nowTime);	
		} 

		return isFree;
	}

	self.pushWork = function(nowTime) {
		isFree = false;
		timeNewWork = nowTime + randFromMinToMax(self.min, self.max);
	}
} 
