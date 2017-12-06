include('src/random.js'); 

function SourceOfInformation(min, max) {
	let self = this;
	
	self.min = min;
	self.max = max;

	let isRequest = false;

	let timeNewOrder = randFromMinToMax(self.min, self.max);

	self.isRequest = function(nowTime) {
		if (nowTime >= timeNewOrder && !isRequest)  {
			isRequest = true;
			timeNewOrder += randFromMinToMax(self.min, self.max);
		}

		return isRequest;
	}

	self.reset = function() {
		isRequest = false;
	}
}
 
