include('src/random.js');


function ServiceUnitByPoisson(releasingOrder, lambda) {
	let self = this;

	self.lambda = lambda;

	self.isFree = false;
	var lastIsFree = false;

	let timeNewWork = randByPoisson(self.lambda);

	self.isState = () => {
		return lastIsFree ? 1 : 0
	}

	var getState = (nowTime) => {
		if (nowTime >= timeNewWork) {
			self.isFree = true;
			lastIsFree = true;

			timeNewWork += randByPoisson(self.lambda);
		} else {
			lastIsFree = false;
		}

		return self.isFree;
	}

	var giveOrder = (bm) => {
		if (releasingOrder) bm.shift();
		self.isFree = false;
	}

	self.run = (nowTime, bm) => {
		if (getState(nowTime)) giveOrder(bm);
	}
}