static int
nft_rule_expr_nat_snprintf_json(char *buf, size_t size,
				struct nft_rule_expr *e)
{
	struct nft_expr_nat *nat = (struct nft_expr_nat *)e->data;
	int len = size, offset = 0, ret = 0;

	switch (nat->type) {
	case NFT_NAT_SNAT:
		ret = snprintf(buf, len,
			"\"type\" : \"NFT_NAT_SNAT\",");
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);
		break;
	case NFT_NAT_DNAT:
		ret = snprintf(buf, len,
			"\"type\" : \"NFT_NAT_DNAT\",");
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);
		break;
	}

	ret = snprintf(buf, len, "\"family\" : \"%s\",",
		       nat->family == AF_INET ? "AF_INET" : "AF_INET6");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	if (e->flags & (1 << NFT_EXPR_NAT_REG_ADDR_MIN)) {
		ret = snprintf(buf, len, "\"sreg_addr_min_v4\" : %u,"
				" \"sreg_addr_max_v4\" : %u,",
			       nat->sreg_addr_min, nat->sreg_addr_max);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);
	}

	if (e->flags & (1 << NFT_EXPR_NAT_REG_PROTO_MIN)) {
		ret = snprintf(buf, len, "\"sreg_proto_min\" : %u,"
				"\"sreg_proto_max\" : %u",
		       nat->sreg_proto_min, nat->sreg_proto_max);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);
	}

	return offset;
}
