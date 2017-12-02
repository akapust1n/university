include('src/random.js');

function SourceOfInformation(a, b) {
	let self = this;

	self.a = a;
	self.b = b;

	self.isOrder = false;

	var lastIsOrder = false;


	let timeNewOrder = randFromMinToMax(self.a, self.b);

	self.isState = () => {
		return lastIsOrder ? 1 : 0
	}

	let getState = (nowTime) => {
		if (nowTime >= timeNewOrder) {
			self.isOrder = true;
			lastIsOrder = true;
			timeNewOrder += randFromMinToMax(self.a, self.b);
		} else {
			lastIsOrder = false;
		}

		return self.isOrder;
	}

	let getOrder = (bm) => {
		bm.push("что-то");
		self.isOrder = false;
	}

	self.run = (nowTime, bm) => {
		if (getState(nowTime)) getOrder(bm);
	}
}