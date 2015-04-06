<?php

$I = new ApiTester($scenario);
$I->wantTo('Get user with not exists id');
$I->sendGET('users/500000000');
$I->seeResponseCodeIs(404);
$I->seeResponseIsJson();
$I->haveHttpHeader('Content-Type','application/json');
