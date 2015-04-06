<?php

$I = new ApiTester($scenario);
$I->wantTo('Get user');
$I->sendGET('users/1');
$I->seeResponseCodeIs(200);
$I->seeResponseIsJson();
$I->haveHttpHeader('Content-Type','application/json');
