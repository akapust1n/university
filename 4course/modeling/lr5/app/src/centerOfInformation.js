include('src/source-of-information.js');
include('src/service-unit.js');

function findProbabilityOfFailure(simulator, lClient, lOperators, lStores) {
	let client = new SourceOfInformation(lClient.min, lClient.max);

	let stores = [];
	lStores.forEach(function (el) {
		stores.push(new Store(el.time));
	})

	let operators = [];
	operators.push(new ServiceUnit(lOperators[0].min, lOperators[0].max, stores[0]));
	operators.push(new ServiceUnit(lOperators[1].min, lOperators[1].max, stores[0]));
	operators.push(new ServiceUnit(lOperators[2].min, lOperators[2].max, stores[1]));


	let nowTime = 0;
	let amountInput = 0;
	let amountLost = 0;
	let amountOutput = 0;

	let dataState = [];

	let flag = true;

	while (flag) {
		if (client.isRequest(nowTime)) {
			let isServed = operators.some(operator => {
				if (operator.isFree(nowTime)) {
					operator.pushWork(nowTime);
					client.reset();
					return true;
				}

				return false;
			})

			dataState.push([nowTime, isServed ? 0 : 1]);

			if (!isServed) {
				++amountLost;
				client.reset();
			}

			++amountInput;
		}

		stores.every(function (el) {
			amountOutput += el.run(nowTime);
		})

		if (simulator.onInput) {
			flag = (amountInput < simulator.amountRequest);
		} else {
			flag = (amountOutput < simulator.amountRequest);
		}

		nowTime += simulator.dt;
	}


	return {
		probabilityFailure: amountLost / amountInput,
		amountLost: amountLost,
		amountInput: amountInput,
		amountOutput: amountOutput,
		allTime: nowTime
	}
}