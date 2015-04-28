<?php

namespace Owl\Console;

class Application
{

    protected $commands;



    public function getCommands() {}

    /**
     * @param mixed $command 
     */
    public function addCommand(CommandInterface $command) {}

    /**
     * @param array $commands 
     */
    public function addCommands($commands) {}

}
