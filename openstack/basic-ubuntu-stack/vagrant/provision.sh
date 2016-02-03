#!/bin/bash -x

# https://github.com/mitchellh/vagrant/issues/1673#issuecomment-17237843
# the erros "stdin: is not a tty" and "re-open stdin" is not a problem of vagrant
# This provisioning just ignores these cautions.

sudo apt-get -qqy update
sudo apt-get -qqy install -y apache2

# referenced by dokenstack : https://github.com/ewindisch/dockenstack
sudo apt-get -qqy install git socat curl sudo vim wget net-tools
sudo apt-get -qqy install build-essential
sudo apt-get -qqy install rabbitmq-server
useradd -U -G sudo -s /bin/bash -m stack
echo "stack ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
