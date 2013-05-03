static int
nft_rule_expr_lookup_snprintf_json(char *buf, size_t size,
				  struct nft_expr_lookup *l)
{
	int len = size, offset = 0, ret;

	ret = snprintf(buf, len, "\"set\" : \"%s\", \"sreg\" : %u \"dreg\" : %u",
			l->set_name, l->sreg, l->dreg);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	return offset;
}
