ans_file="ans_$(date +"%T").txt"
controller_ip="100.100.100.22"

compute_ip_prefix="100.100.101"
compute_ips=("$compute_ip_prefix.22" "$compute_ip_prefix.23" "$compute_ip_prefix.24")

packstack --gen-answer-file $ans_file

sed -i "s/CONFIG_DEFAULT_PASSWORD=.*/CONFIG_DEFAULT_PASSWORD=openstack/g" $ans_file
sed -i "s/PW=.*/PW=openstack/g" $ans_file

# IP configurations
sed -i "s/HOST=.*/HOST=$controller_ip/g" $ans_file
sed -i "s/HOSTS=.*/HOSTS=$controller_ip/g" $ans_file
sed -i "s/10.0.2.15/$controller_ip/g" $ans_file
sed -i "s/CONFIG_COMPUTE_HOSTS=.*/CONFIG_COMPUTE_HOSTS=${compute_ips[0]},${compute_ips[1]},${compute_ips[2]}/g" $ans_file

# Enable L3, LBass, FWass
sed -i "s/CONFIG_LBAAS_INSTALL=n/CONFIG_LBAAS_INSTALL=y/g" $ans_file
sed -i "s/CONFIG_NEUTRON_METERING_AGENT_INSTALL=n/CONFIG_NEUTRON_METERING_AGENT_INSTALL=y/g" $ans_file
sed -i "s/CONFIG_NEUTRON_FWAAS=n/CONFIG_NEUTRON_FWAAS=y/g" $ans_file

# Driver
sed -i "s/CONFIG_NEUTRON_ML2_TYPE_DRIVERS=.*/CONFIG_NEUTRON_ML2_TYPE_DRIVERS=flat,vlan,gre,vxlan/g" $ans_file
sed -i "s/CONFIG_NEUTRON_ML2_TENANT_NETWORK_TYPES=.*/CONFIG_NEUTRON_ML2_TENANT_NETWORK_TYPES=local,vlan,gre,vxlan/g" $ans_file
sed -i "s/CONFIG_NEUTRON_ML2_MECHANISM_DRIVERS=.*/CONFIG_NEUTRON_ML2_MECHANISM_DRIVERS=linuxbridge,l2population/g" $ans_file

# Network range
sed -i "s/CONFIG_NEUTRON_ML2_FLAT_NETWORKS=.*/CONFIG_NEUTRON_ML2_FLAT_NETWORKS=physnet2/g" $ans_file
sed -i "s/CONFIG_NEUTRON_ML2_VLAN_RANGES=.*/CONFIG_NEUTRON_ML2_VLAN_RANGES=physnet3:30:99/g" $ans_file
sed -i "s/CONFIG_NEUTRON_ML2_TUNNEL_ID_RANGES=.*/CONFIG_NEUTRON_ML2_TUNNEL_ID_RANGES=1:1000/g" $ans_file
sed -i "s/CONFIG_NEUTRON_ML2_VNI_RANGES=.*/CONFIG_NEUTRON_ML2_VNI_RANGES=1:1000/g" $ans_file

# Network agents
sed -i "s/CONFIG_NEUTRON_L2_AGENT=.*/CONFIG_NEUTRON_L2_AGENT=linuxbridge/g" $ans_file
sed -i "s/CONFIG_NEUTRON_LB_INTERFACE_MAPPINGS=.*/CONFIG_NEUTRON_LB_INTERFACE_MAPPINGS=physnet2:enp0s9,physnet3:enp0s10/g" $ans_file
