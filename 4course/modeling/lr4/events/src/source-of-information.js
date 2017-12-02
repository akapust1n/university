include('src/random.js'); 

function SourceOfInformation(a, b) {
	let self = this;
	
	self.a = a;
	self.b = b;

	self.getNextTime = function() {
		return randFromMinToMax(self.a, self.b);
	}

	self.run = function(bm) {
		bm.push("что-то");
	}
}
 
