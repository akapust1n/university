include('src/random.js');


function ServiceUnitByPoisson(releasingOrder, lambda) {
	let self = this;
	
	self.lambda = lambda;

	self.getNextTime = function() {
		return randByPoisson(self.lambda);
	}

	self.run = function(bm) {
		if (releasingOrder) bm.shift();
	}
} 
